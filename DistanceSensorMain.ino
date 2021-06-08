#include <Wire.h>
#include <VL53L0X.h>

#define TranA 10 
#define TranB 11 

VL53L0X sensor;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(TranA, OUTPUT);
  pinMode(TranB, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void zero()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, HIGH);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, LOW);

}

void one()
{
  digitalWrite(2, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, HIGH);

  digitalWrite(6, LOW);

  digitalWrite(7, HIGH);

  digitalWrite(8, HIGH);

  digitalWrite(9, HIGH);
}

void two()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, HIGH);

  digitalWrite(5, LOW);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, HIGH);

  digitalWrite(9, LOW);


}

void three()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, HIGH);

  digitalWrite(9, HIGH);


}

void four()
{
  digitalWrite(2, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, LOW);

  digitalWrite(7, HIGH);

  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);

}

void five()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);

}

void six()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, LOW);
}

void seven()
{
  digitalWrite(2, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, HIGH);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);

}

void eight()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, LOW);
}

void nine()
{
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  digitalWrite(6, LOW);

  digitalWrite(7, LOW);

  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);
}

void loop()
{
  int distance = sensor.readRangeContinuousMillimeters() / 10;

  //distance = distance;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }

  Serial.println();
  delay(100);
  if (distance == 1) {
    one();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);    
    }
  } else if (distance == 2) {
    two();
    bool wan2 = true;
    digitalWrite(TranB, HIGH);
    while (wan2 == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 3) {
    three();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 4) {
    four();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 5) {
    five();
    digitalWrite(TranB, HIGH);
    bool wan = true;
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 6) {
    six();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 7) {
    seven();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == 1) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 8) {
    eight();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 9) {
    nine();
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == 1) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      zero();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 10) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      zero();
      delay(1);
    }
  } else if (distance == 11) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);
    }
  } else if (distance == 12) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 13) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 14) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 15) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 16) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 17) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 18) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 19) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      one();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 20) {
    //two();
    bool wan = true;
    //digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranA, LOW);
      digitalWrite(TranB, HIGH);
      zero();
      delay(1);
    }
  } else if (distance == 21) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);
    }
  } else if (distance == 22) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 23) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 24) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 25) {
    bool wan = true;
    two();
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 26) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 27) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 28) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 29) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      two();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 30) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      zero();
      delay(1);
    }
  } else if (distance == 31) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);
    }
  } else if (distance == 32) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 33) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 34) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 35) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 36) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 37) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 38) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 39) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      three();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 40) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      zero();
      delay(1);
    }
  } else if (distance == 41) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);
    }
  } else if (distance == 42) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 43) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 44) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 45) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 46) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 47) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 48) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 49) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      four();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 50) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      zero();
      delay(1);
    }
  } else if (distance == 51) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      one();
      delay(1);
    }
  } else if (distance == 52) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      two();
      delay(1);
    }
  } else if (distance == 53) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      three();
      delay(1);
    }
  } else if (distance == 54) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      four();
      delay(1);
    }
  } else if (distance == 55) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      five();
      delay(1);
    }
  } else if (distance == 56) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      six();
      delay(1);
    }
  } else if (distance == 57) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      seven();
      delay(1);
    }
  } else if (distance == 58) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      eight();
      delay(1);
    }
  } else if (distance == 59) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      five();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      nine();
      delay(1);
    }
  } else if (distance == 60) {
    bool wan = true;
    digitalWrite(TranB, HIGH);
    while (wan == true) {
      digitalWrite(TranA, HIGH);
      delay(1);
      digitalWrite(TranB, LOW);
      six();
      delay(1);
      digitalWrite(TranB, HIGH);
      digitalWrite(TranA, LOW);
      zero();
      delay(1);
    }
  }
}
