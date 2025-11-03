  #include <Arduino.h>
  #include <RF24.h>
  #include "Transmitter.h"

  const byte addressesX[][6] = {"Base0", "Play1", "Play2"};

  Transmitter::Transmitter(RF24 &_radio, const byte *_address) : 
    radio(_radio) {
    // radio = _radio;
    address = _address;
  }

  void Transmitter::setup() {
    
  }

  void Transmitter::loop() {
    
  }

  bool Transmitter::transmit(PayloadStruct payload) {
    radio.openWritingPipe(address);
    radio.stopListening();
    bool result;
    result = radio.write(&payload, sizeof(PayloadStruct));
    Serial.println((String)"payload.key: " + payload.key + "  -  payload.value: " + payload.value + " in transmit");
    delay(150);
    if (result) {
      // Serial.println((String)"result: " + result);
      if (radio.isAckPayloadAvailable()) {
        bool response;
        radio.read(&response, sizeof(response));
        // Serial.print("response: ");
        // Serial.println(response);
        if (response == true) {
          return true;
        }
        else {
          return false;
        }
      }
      else {
        return false;
      }
    }
    else {
      Serial.println((String)"payload.key " + payload.key + " failed");
    }
    radio.startListening();
    return result;
  }

  byte Transmitter::transmitWithResponse(PayloadStruct payload) {
    radio.openWritingPipe(address);
    radio.stopListening();
    bool result;
    result = radio.write(&payload, sizeof(PayloadStruct));
    Serial.println((String)"yyy payload.key: " + payload.key + "  -  payload.value: " + payload.value + " in transmit");
    delay(150);
    if (result) {
      Serial.println((String)"result: " + result);
      if (radio.isAckPayloadAvailable()) {
        byte response;
        radio.read(&response, sizeof(response));
        Serial.println((String)"response: " + response);
        radio.startListening();
        return response;
      }
      else {
        return 0;
      }
    }
    else {
      Serial.println((String)"payload.key " + payload.key + " failed");
      radio.startListening();
      return 0;
    }
  }
