/**
 * Miwesta - MIcro WEather STAtion
 * Copyright (C) 2019  Vitor Guia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Arduino version 2.0
 *
 * @author    Vitor Guia <contato@vitor.guia.nom.br>
 * @copyright 2019 Vitor Guia
 * @license   http://www.gnu.org/licenses GPL-3.0-or-later
 * @see       https://gitlab.com/vitoranguia/miwesta Repository of Miwesta
 */

/** DHT11 */
#include <Adafruit_Sensor.h>
#include <DHT.h>

/** DHT11 */
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

/** YL-38 */
byte rainPinAnalog = A5;
byte rainPinDigital = 7;

void setup() {
    Serial.begin(9600);

    /** DHT11 */
    dht.begin();

    /** YL-38 */
    pinMode(rainPinAnalog, INPUT);
    pinMode(rainPinDigital, INPUT);
}

void loop() {
    /** DHT11 */
    int rainAnalog = analogRead(rainPinAnalog);
    int rainDigital = digitalRead(rainPinDigital);

    /** YL-38 */
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    /** DHT11 */
    if (rainDigital == 0) {
      if (rainAnalog <= 340) {
          /** 0-340 = 341 */
          Serial.print("Rain Strong; ");
      } else if (rainAnalog >= 341 && rainAnalog <= 681) {
          /** 341-681 = 340 */
          Serial.print("Rain Medium; ");
      } else {
          /** 682-1023 = 341 */
          Serial.print("Rain Low; ");
      }
    }
    Serial.print("Rain Analog: ");
    Serial.print(rainAnalog);
    Serial.print("; Rain Digital: ");
    Serial.print(rainDigital);

    /** YL-38 */
    Serial.print("; Humidity: ");
    Serial.print(humidity);
    Serial.print("%; Temperature: ");
    Serial.print(temperature);
    Serial.println("*C.");

    delay(1000);
}
