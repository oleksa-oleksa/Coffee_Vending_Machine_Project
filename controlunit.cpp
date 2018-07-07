// Implemented by Oleksandra Baga
#include "controlunit.h"
#include "serviceroutine.h"

ControlUnit::ControlUnit() : ingredientTanks(NULL)
{
    activeUserChoice = NULL;
    ingredientTanks = new Ingredient();
}

void ControlUnit::linkInteractionUnit(InteractionUnit *iunit)
{
    qDebug() << "CONTROL_UNIT: InteractionUnit linked";
    this->iunit = iunit;
}

ControlUnit::~ControlUnit()
{
    if (ingredientTanks)
        delete ingredientTanks;
}

void ControlUnit::setDisplayBacklight()
{

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

    checkCardReader();
    activeUserChoice->setSelectedDrink(NO_DRINK);
    opticalSensor->setDistanceToObject(10);
    opticalSensor->getOpticalFlowSensorsMeasurements();
    setDisplayBacklight();


}


bool ControlUnit::checkCardReader()
{
    return cardScanner->getIsCardInside();
}

bool ControlUnit::checkCard()
{
    return cardScanner->isValidCardInside();
}



CardHolderState ControlUnit::insertCard(Card *card)
{
    // if NO card in RFID
    if (!checkCardReader())
    {
        // After card was inserted, the RFID Scanner provides verification
        // without instructions outside
        // modifies private attribute isChoiceAllowed for InteractionUnit
        if (cardScanner->insertCard(card))
        {
            display->writeGreetingText(activeUserChoice);

            return VALID_CARD_INSIDE;
        }

        // if card is not valid, it will be automaticaly ejected (simulation in Design)
        // and the purschasing will be ended
        // the next card can be inserted in RFID
        else
        {
            display->writeErrorText();
            cardScanner->ejectCard();

            return NONVALID_CARD_INSIDE;
        }
    }

    // if there IS A CARD
    else
    {
        cardScanner->ejectCard();
        delete(activeUserChoice);
        activeUserChoice = iunit->initUserChoice(card);
        activeUserChoice->setDefaultChoice();
        display->writeDefaultText(activeUserChoice);

        return NO_CARD;
    }
}

// we need two sensors for three states: no cup, empty cup, cup with drink
CupHolderState ControlUnit::checkCupHolder()
{
    // if cup detected
    if (opticalSensor->getOpticalValue())
    {
        // and a drink was prepared
        if (flow->getHasPreparedDrink())
        {
            qDebug() << "OPTICAL SENSOR: There is a full cup";
            opticalSensor->setDistanceToObject(10);
            opticalSensor->getOpticalFlowSensorsMeasurements();
            return FULL_CUP;
        }

        // only cup stays and no drink was prepared
        else
        {
            qDebug() << "OPTICAL SENSOR: There is an empty cup";
            opticalSensor->setDistanceToObject(10);
            opticalSensor->getOpticalFlowSensorsMeasurements();
            return EMPTY_CUP;
        }
    }
    // there is not cup and no drink
    else
    {
        qDebug() << "OPTICAL SENSOR: Cup holder is empty";
        opticalSensor->setDistanceToObject(2);
        opticalSensor->getOpticalFlowSensorsMeasurements();
        return NO_CUP;
    }
}

void ControlUnit::writeMessageLCD(LCD_Message message)
{
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
        display->writeErrorText();
        break;
    case (WAIT_PLEASE):
        break;
    case (TAKE_YOUR_DRINK):
        break;
    case (SYSTEM_ERROR):
        break;
    }
}

void ControlUnit::maintenanceRoutine()
{
    checkIngredients();

// Set sensor and actuator states OK if UNDEFINED

    if (cardScanner->getSensorState() == UNDEFINED)
        cardScanner->setSensorState(OK);

    if (flow->getSensorState() == UNDEFINED)
        flow->setSensorState(OK);

    if (opticalSensor->getSensorState() == UNDEFINED)
        opticalSensor->setSensorState(OK);

    if (pressureSensor->getSensorState() == UNDEFINED)
        pressureSensor->setSensorState(OK);

    if (temperatureSensor->getSensorState() == UNDEFINED)
        temperatureSensor->setSensorState(OK);

    if (brightSensor->getSensorState() == UNDEFINED)
        brightSensor->setSensorState(OK);

    if (display->getActuatorState() == UNDEFINED)
        display->setActuatorState(OK);

//    for (int i = 0; i < AMOUNT_OF_MOTORS; i++)
//    {
//        if (motor[i]->getActuatorState() == UNDEFINED)
//            motor[i]->setActuatorState(OK);
//    }

    if (heater->getActuatorState() == UNDEFINED)
        heater->setActuatorState(OK);

    if (brew->getActuatorState() == UNDEFINED)
        brew->setActuatorState(OK);

    if (milkMaker->getActuatorState() == UNDEFINED)
        milkMaker->setActuatorState(OK);

    qDebug() << "CONTROL_UNIT: Initialisation done. State is OK.";
}

void ControlUnit::staffServiceRoutine()
{
    ServiceRoutine sr;
    sr.refillOrNot(this->ingredientTanks);
}

bool ControlUnit::checkIngredients()
{
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

bool ControlUnit::checkStartConditions()
{
    // get Optical Sensor Measurements
    if (opticalSensor->getOpticalFlowSensorsMeasurements() == NO_CUP) {
        qDebug() << "OPTICAL SENSOR: Place your cup first!";
        return false;
    }
    else if (opticalSensor->getOpticalFlowSensorsMeasurements() == FULL_CUP) {
        qDebug() << "OPTICAL SENSOR: Take your cup with prepared drink before order a new one! :)";
        return false;
    }

    else if (opticalSensor->getOpticalFlowSensorsMeasurements() == EMPTY_CUP) {
        // PASSED
        qDebug() << "OPTICAL SENSOR: Cup is OK, liquid can flow!";
    }
    //==============================================================
    // check if drink is preselected
    if (activeUserChoice->getSelectedDrink() == NO_DRINK) {
        qDebug() << "CONTROL UNIT: Select drink first!";
        return false;
    }

    // check if card is still in the card holder
    if (cardScanner->isValidCardInside() != VALID_CARD_INSIDE)
    {
        qDebug() << "RFID SCANNER: Card missed, please return your card back!";
        return false;
    }

    if (!checkIngredients()) {
        qDebug() << "CONTROL UNIT: Error: Not enough ingredients...";
        return false;
    }

    // if it is possible to get here, the payment process could start
    if (activeUserChoice->payDrink())
    {
        qDebug() << "CONTROL UNIT: We can start prepare drink! Yahoo!";
        qDebug() << "CONTROL UNIT: You can purchase next drink after this one will be prepared!";
        return true;
    }
    else
    {
        qDebug() << "CONTROL UNIT: Payment error!";
        qDebug() << "CONTROL UNIT: Take your card!";
        return false;
    }
}

bool ControlUnit::prepareSelectedDrink()
{
    if (!checkIngredients()) {
        qDebug() << "CONTROL UNIT: Preparation Error! Aborted";
        abortPreparation();
        return false;
    }
    return true;
}

void ControlUnit::abortPreparation()
{
    activeUserChoice->setDefaultChoice();
    writeMessageLCD(USER_CHOICE);
}


void ControlUnit::connectRFID(RFID_Scanner *sensor)
{
    cardScanner = sensor;
}
void ControlUnit::connectOptical(OpticalSensor *sensor)
{
    opticalSensor = sensor;
}
void ControlUnit::connectPressure(PressureSensor *sensor)
{
    pressureSensor = sensor;
}
void ControlUnit::connectTemperatur(TemperaturSensor *sensor)
{
    temperatureSensor = sensor;
}

void ControlUnit::connectBrightnessSensor(BrightnessSensor *sensor)
{
    brightSensor = sensor;
}
void ControlUnit::connectFlow(Flowmeter *sensor)
{
    flow = sensor;
}

void ControlUnit::connectLCD(LCD_Display *actuator)
{
    display = actuator;
}
void ControlUnit::connectMotor(DC_Motor *actuator, int numOfActuators)
{
  for(int i = 0; i < numOfActuators; i++) {
      motor[i] = &actuator[i];
  }
}

void ControlUnit::connectHeater(Waterheater *actuator)
{
    heater = actuator;
}
void ControlUnit::connectMilkMaker(Milkmaker *actuator)
{
    milkMaker = actuator;
}

void ControlUnit::connectBrewGroup(Brewgroup *actuator)
{
    brew = actuator;
}


void ControlUnit::blockCupHolder()
{
    qDebug() << "CONTROL UNIT: Cup Holder is blocked, the cup will be realeased after drink preparing the drink";
}


void ControlUnit::unblockCupHolder()
{
    qDebug() << "CONTROL UNIT: Cup Holder is unblocked";

}

