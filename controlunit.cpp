// Implemented by Oleksandra Baga
#include "controlunit.h"
#include "serviceroutine.h"
#include <QCoreApplication>
#include <math.h>

ControlUnit::ControlUnit() : ingredientTanks(NULL) {
    activeUserChoice = NULL;
    ingredientTanks = new Ingredient();
}

void ControlUnit::linkInteractionUnit(InteractionUnit *iunit) {
    qDebug() << "CONTROL_UNIT: InteractionUnit linked";
    this->iunit = iunit;
}

ControlUnit::~ControlUnit() {
    if (ingredientTanks)
        delete ingredientTanks;
}

void ControlUnit::setDisplayBacklight() {

    qDebug() << "CONTROL UNIT: setDisplayBacklight() started.";

    if (brightSensor->getBrightness() < 3 && !display->getBacklight()) {
        display->setBacklight(true);
        qDebug() << "LCD: Backlight turned on (BRIGHTNESS SENSOR)";
    }
    else if (brightSensor->getBrightness() >= 3 && display->getBacklight()) {
        display->setBacklight(false);
        qDebug() << "LCD: Backlight turned off (BRIGHTNESS SENSOR)";

    }
}

void ControlUnit::onStartInit() {

    qDebug() << "CONTROL UNIT: onStartInit() started.";
    qDebug() << "CONTROL UNIT: CREDIT_LIMIT = 5.0. You can change the limit in account.cpp";
    checkCardReader();
    activeUserChoice->setSelectedDrink(NO_DRINK);
    opticalSensor->setDistanceToObject(10);
    opticalSensor->getOpticalFlowSensorsMeasurements();
    setDisplayBacklight();
}

bool ControlUnit::checkCardReader() {
    return cardScanner->getIsCardInside();
}

bool ControlUnit::checkCard() {
    return cardScanner->isValidCardInside();
}



CardHolderState ControlUnit::insertCard(Card *card) {
    qDebug() << "CONTROL UNIT: insertCard() started.";
    // if NO card in RFID
    if (!checkCardReader()) {
        // After card was inserted, the RFID Scanner provides verification
        // without instructions outside
        // modifies private attribute isChoiceAllowed for InteractionUnit
        if (cardScanner->insertCard(card)) {
            display->writeGreetingText(activeUserChoice);

            return VALID_CARD_INSIDE;
        }

        // if card is not valid, it will be automaticaly ejected (simulation in Design)
        // and the purschasing will be ended
        // the next card can be inserted in RFID
        else {
            display->writeCardErrorText();
            cardScanner->ejectCard();
            return NONVALID_CARD_INSIDE;
        }
    }

    // if there IS A CARD
    else {
        cardScanner->ejectCard();
        delete(activeUserChoice);
        activeUserChoice = iunit->initUserChoice(card);
        activeUserChoice->setDefaultChoice();
        display->writeDefaultText(activeUserChoice);
        return NO_CARD;
    }
}

bool ControlUnit::isBrewingFinished() {
    return opticalSensor->getOpticalValue() && flow->getHasPreparedDrink();
}


// we need two sensors for three states: no cup, empty cup, cup with drink
CupHolderState ControlUnit::checkCupHolder() {
    qDebug() << "CONTROL UNIT: checkCupHolder() started.";
    // if cup detected
    if (opticalSensor->getOpticalValue()) {
        // and a drink was prepared
        if (flow->getHasPreparedDrink()) {
            qDebug() << "OPTICAL SENSOR: There is a full cup";
            opticalSensor->setDistanceToObject(10);
            opticalSensor->getOpticalFlowSensorsMeasurements();
            writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_FULL_CUP);
            return FULL_CUP;
        }

        // only cup stays and no drink was prepared
        else {
            qDebug() << "OPTICAL SENSOR: There is an empty cup";
            opticalSensor->setDistanceToObject(10);
            opticalSensor->getOpticalFlowSensorsMeasurements();
            return EMPTY_CUP;
        }
    }
    // there is not cup and no drink
    else {
        qDebug() << "OPTICAL SENSOR: Cup holder is empty";
        opticalSensor->setDistanceToObject(2);
        opticalSensor->getOpticalFlowSensorsMeasurements();
        return NO_CUP;
    }
}

void ControlUnit::writeMessageLCD(LCD_Message message) {
    switch (message) {
    case (DEFAULT):
        display->writeDefaultText(activeUserChoice);
        break;
    case (GREETING):
        display->writeGreetingText(activeUserChoice);
        break;
    case (USER_CHOICE):
        display->writeUserChoiceText(activeUserChoice);
        break;
    case (ERROR):
        display->writeCardErrorText();
        break;
    case (WAIT_PLEASE):
        display->writeWaitText();
        break;
    case (TAKE_YOUR_DRINK):
        display->writeTakeDrinkMessage();
        break;    
    case (PAYMENT_ERROR):
        display->writeSystemErrorMessage(PREPARE_ERROR_PAYMENT);
        break;
    default:
        break;
    }
}

void ControlUnit::writeMessageLCD(LCD_Message message, PreparationStatus status) {
    switch (message) {
    case (SYSTEM_ERROR):
        display->writeSystemErrorMessage(status);
        break;
    default:
        break;
    }
}

void ControlUnit::maintenanceRoutine() {
    qDebug() << "CONTROL UNIT: maintenanceRoutine() started.";

    checkIngredients();

// Set sensor and actuator states OK if UNDEFINED

    if (cardScanner->getSensorState() == UNDEFINED)
        cardScanner->setSensorState(OK);

    if (flow->getSensorState() == UNDEFINED)
        flow->setSensorState(OK);

    if (opticalSensor->getSensorState() == UNDEFINED)
        opticalSensor->setSensorState(OK);

    if (temperatureSensor->getSensorState() == UNDEFINED)
        temperatureSensor->setSensorState(OK);

    if (brightSensor->getSensorState() == UNDEFINED)
        brightSensor->setSensorState(OK);

    if (display->getActuatorState() == UNDEFINED)
        display->setActuatorState(OK);

    for (int i = 0; i < AMOUNT_OF_MOTORS; i++) {
        if (motor[i]->getActuatorState() == UNDEFINED)
            motor[i]->setActuatorState(OK);
    }

    if (heater->getActuatorState() == UNDEFINED)
        heater->setActuatorState(OK);

    if (milkMaker->getActuatorState() == UNDEFINED)
        milkMaker->setActuatorState(OK);

    qDebug() << "CONTROL_UNIT: Initialisation done. State is OK.";
}

void ControlUnit::staffServiceRoutine() {
    ServiceRoutine sr;
    sr.refillOrNot(this->ingredientTanks);
    // reset all sensors and actuators
    maintenanceRoutine();
}

bool ControlUnit::checkIngredients() {
    qDebug() << "CONTROL UNIT: checkIngredients() started.";

    if (activeUserChoice->getSelectedDrink() == HOTWATER) {
        qDebug() << "CONTROL UNIT: Water is OK!";
        return true; // it is assumed that we always have water
    }

    if (!checkSugarAmount()) {
        return false;
    }

    if (!checkMilkAmount()) {
        return false;
    }

    if (activeUserChoice->getSelectedDrink() == CACAO) {
        if (!checkCacaoIngredient()) {
            return false;
        }
    }
    else if (activeUserChoice->getSelectedDrink() != HOTWATER) {
        if (!checkCoffeeIngredient()) {
            return false;
        }
    }

    qDebug() << "CONTROL UNIT: All Ingredients are OK!";
    return true;
}

bool ControlUnit::checkCacaoIngredient() {
    if (ingredientTanks->getCacaoIngredient() < activeUserChoice->getSpecificRecipeComponent() + MINIMAl_THRESHOLD) {
        qDebug() << "CONTROL UNIT: Cacao Powder is not enough!";
        return false;
    }
    return true;
}

bool ControlUnit::checkCoffeeIngredient() {
    if (ingredientTanks->getCoffeeIngredient() < activeUserChoice->getSpecificRecipeComponent() + MINIMAl_THRESHOLD) {
        qDebug() << "CONTROL UNIT: Coffee Powder is not enough!";
        return false;
    }
    return true;
}

bool ControlUnit::checkSugarAmount() {
    if (ingredientTanks->getSugarIngredient() < activeUserChoice->getSugarAmount() + MINIMAl_THRESHOLD) {
        qDebug() << "CONTROL UNIT: Sugar is not enough!";
        return false;
    }
    return true;
}

bool ControlUnit::checkMilkAmount() {
    if (ingredientTanks->getMilkIngredient() < activeUserChoice->getMilkAmount() + MINIMAl_THRESHOLD) {
        qDebug() << "CONTROL UNIT: Milk is not enough!";
        return false;
    }
    return true;
}

PreparationStatus ControlUnit::checkStartConditions() {
    // get Optical Sensor Measurements
    if (opticalSensor->getOpticalFlowSensorsMeasurements() == NO_CUP) {
        qDebug() << "OPTICAL SENSOR: Place your cup first!";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_NO_CUP);
        return PREPARE_ERROR_NO_CUP;
    }
    else if (opticalSensor->getOpticalFlowSensorsMeasurements() == FULL_CUP) {
        qDebug() << "OPTICAL SENSOR: Take your cup with prepared drink before order a new one! :)";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_FULL_CUP);
        return PREPARE_ERROR_FULL_CUP;
    }

    else if (opticalSensor->getOpticalFlowSensorsMeasurements() == EMPTY_CUP) {
        // PASSED
        qDebug() << "OPTICAL SENSOR: Cup is OK, liquid can flow!";
    }
    //==============================================================
    // check if drink is preselected
    if (activeUserChoice->getSelectedDrink() == NO_DRINK) {
        qDebug() << "CONTROL UNIT: Select drink first!";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_NO_DRINK);
        return PREPARE_ERROR_NO_DRINK;
    }

    // check if card is still in the card holder
    if (cardScanner->isValidCardInside() != VALID_CARD_INSIDE) {
        qDebug() << "RFID SCANNER: Card missed, please return your card back!";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_NO_CARD);
        return PREPARE_ERROR_NO_CARD;
    }

    if (!checkIngredients()) {
        qDebug() << "CONTROL UNIT: Error: Not enough ingredients...";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_NO_INGREDIENT);
        return PREPARE_ERROR_NO_INGREDIENT;
    }

    // if it is possible to get here, the payment process could start
    if (activeUserChoice->payDrink()) {
        qDebug() << "CONTROL UNIT: YOU HAVE PAID! WE CAN START PREPARE A DRINK!";
        writeMessageLCD(WAIT_PLEASE);
        return PREPARE_IS_ALLOWED;
    }
    else {
        qDebug() << "CONTROL UNIT: Payment error!";
        qDebug() << "CONTROL UNIT: Take your card!";
        writeMessageLCD(SYSTEM_ERROR, PREPARE_ERROR_PAYMENT);
        return PREPARE_ERROR_PAYMENT;
    }
}

PreparationStatus ControlUnit::prepareSelectedDrink() {
    writeMessageLCD(WAIT_PLEASE);

    if (!checkIngredients()) {
        qDebug() << "CONTROL UNIT: Not enough ingredients. Aborted...";
        abortPreparation();
        return PREPARE_ERROR_NO_INGREDIENT;
    }

    //=============================================================
    // heat water to the recipe temperature
    heater->setWorkTemperature(activeUserChoice->getRecipeTemperature());
    heater->heatWater();

    // Waiting for water heating
    while (heater->getIsHeating()) {
        QCoreApplication::instance()->processEvents();
    }
    // put the heater back in a idle state
    heater->setWorkTemperature(heater->getIdleTemperature());

    if (!temperatureSensor->compareTemperature()) {
        qDebug() << "CONTROL UNIT: Water heater does not heat a water. Aborted...";
        abortPreparation();
        return PREPARE_ERROR_HEATER;
    }

    //=============================================================
    // Motor Simulation for Drink Mixing
    if (activeUserChoice->getSelectedDrink() != HOTWATER) {
        MotorType optionalMotor = MOTOR_TYPES_NUMBER;

        motor[MOTOR_SUGAR]->rotate(activeUserChoice->getSugarAmount());
        ingredientTanks->setSugarIngredient(ingredientTanks->getSugarIngredient() - activeUserChoice->getSugarAmount());

        motor[MOTOR_MILK]->rotate(activeUserChoice->getMilkAmount());
        ingredientTanks->setMilkIngredient(ingredientTanks->getMilkIngredient() - activeUserChoice->getMilkAmount());

        if (activeUserChoice->getSelectedDrink() != CACAO) {
            motor[MOTOR_COFFEE]->rotate(activeUserChoice->getSpecificRecipeComponent());
            ingredientTanks->setCoffeeIngredient(ingredientTanks->getCoffeeIngredient() - activeUserChoice->getSpecificRecipeComponent());
            optionalMotor = MOTOR_COFFEE;
        }
        else {
            motor[MOTOR_CACAO]->rotate(activeUserChoice->getSpecificRecipeComponent());
            ingredientTanks->setCacaoIngredient(ingredientTanks->getCacaoIngredient() - activeUserChoice->getSpecificRecipeComponent());
            optionalMotor = MOTOR_CACAO;
        }

        // Waiting for rotation
        while (motor[MOTOR_SUGAR]->getIsRotating() ||
               motor[MOTOR_MILK]->getIsRotating() ||
               motor[optionalMotor]->getIsRotating()) {
            QCoreApplication::instance()->processEvents();
        }
    }

    //=============================================================
    // Make Milk Foam if required
    // it is assumed milk maker can not have an error state and a drink will be prepared anyway
    if (activeUserChoice->getSelectedDrink() == CAPPUCCINO || activeUserChoice->getSelectedDrink() == LATTEMACCHIOTO) {
        milkMaker->makeMilkFoam(activeUserChoice->getSelectedDrink());
    }

    //=============================================================
    // Pour a drink into a cup
    flow->setRecipeAmountOfLiquid(activeUserChoice);
    if (flow->mainFlowmeterRoutine()) {
        qDebug() << "CONTROL UNIT: Flowmeter has done his task successfuly";
    }
    else {
        qDebug() << "CONTROL UNIT: Flowmeter had a problem during his task";
        return PREPARE_ERROR_FLOW;
    }

    //=============================================================
    writeMessageLCD(TAKE_YOUR_DRINK);
    return PREPARE_DONE;
}

void ControlUnit::abortPreparation() {
    activeUserChoice->setDefaultChoice();
    writeMessageLCD(USER_CHOICE);
}


void ControlUnit::connectRFID(RFID_Scanner *sensor) {
    cardScanner = sensor;
}
void ControlUnit::connectOptical(OpticalSensor *sensor)
{
    opticalSensor = sensor;
}

void ControlUnit::connectTemperatur(TemperaturSensor *sensor) {
    temperatureSensor = sensor;
}

void ControlUnit::connectBrightnessSensor(BrightnessSensor *sensor) {
    brightSensor = sensor;
}

void ControlUnit::connectFlow(Flowmeter *sensor) {
    flow = sensor;
}

void ControlUnit::connectLCD(LCD_Display *actuator) {
    display = actuator;
}

void ControlUnit::connectMotor(DC_Motor *actuator, int numOfActuators) {
  for(int i = 0; i < numOfActuators; i++) {
      motor[i] = &actuator[i];
      motor[i]->setMotorType(static_cast<MotorType>(i));
  }
}

void ControlUnit::connectHeater(Waterheater *actuator) {
    heater = actuator;
}

void ControlUnit::connectMilkMaker(Milkmaker *actuator) {
    milkMaker = actuator;
}

void ControlUnit::blockCupHolder() {
    qDebug() << "CONTROL UNIT: Cup Holder is blocked, the cup will be realeased after drink preparing the drink";
}


void ControlUnit::unblockCupHolder() {
    qDebug() << "CONTROL UNIT: Cup Holder is unblocked";

}

Ingredient *ControlUnit::getIngredients() const {
    return this->ingredientTanks;
}

