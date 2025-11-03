  #ifndef TRANSMITTER_H
  #define TRANSMITTER_H
  #include <Arduino.h>
  #include <RF24.h>

    enum TransmitterResults {
      FAIL = 0,
      SUCCESS = 1
    };

    struct PayloadStruct {
      int key;
      int value;
    };

    class Transmitter {
      public:
        Transmitter(RF24 &_radio, const byte *_address);
        void setup();
        void loop();

        bool transmit(PayloadStruct payload);
        byte transmitWithResponse(PayloadStruct payload);

      private:
        RF24 &radio;
        const byte *address;
    };

  #endif