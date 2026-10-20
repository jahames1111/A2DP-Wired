#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BluetoothA2DPSink.h"

#define I2C_SDA 21
#define I2C_SCL 23
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define PIN_VOL_UP 14
#define PIN_VOL_DOWN 13
#define PIN_PLAY_PAUSE 16
#define PIN_NEXT 17
#define PIN_PREV 19
#define PIN_BATTERY 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BluetoothA2DPSink a2dp_sink;

String current_title = "No Track";
String current_artist = "";
bool is_connected = false;
unsigned long last_update = 0;

void read_metadata(uint8_t id, const uint8_t *text) {
  String content = String((char*)text);
  if (id == ESP_AVRC_MD_ATTR_TITLE) {
    current_title = content;
  } else if (id == ESP_AVRC_MD_ATTR_ARTIST) {
    current_artist = content;
  }
}

void connection_state(esp_a2d_connection_state_t state, void *ptr) {
  if (state == ESP_A2D_CONNECTION_STATE_CONNECTED) {
    is_connected = true;
  } else {
    is_connected = false;
    current_title = "No Track";
    current_artist = "";
  }
}

float get_battery_voltage() {
  int raw = analogRead(PIN_BATTERY);
  return (raw / 4095.0) * 3.3 * 2.0;
}

void update_screen() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.print(is_connected ? "Status: Connected" : "Status: Pairing...");
  
  display.setCursor(85, 0);
  display.print(get_battery_voltage(), 1);
  display.print("V");
  
  display.drawLine(0, 12, 128, 12, SSD1306_WHITE);
  
  display.setCursor(0, 20);
  display.println(current_title);
  display.setCursor(0, 36);
  display.println(current_artist);
  
  display.display();
}

void setup() {
  pinMode(PIN_VOL_UP, INPUT_PULLUP);
  pinMode(PIN_VOL_DOWN, INPUT_PULLUP);
  pinMode(PIN_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(PIN_NEXT, INPUT_PULLUP);
  pinMode(PIN_PREV, INPUT_PULLUP);
  pinMode(PIN_BATTERY, INPUT);
  
  Wire.begin(I2C_SDA, I2C_SCL);
  if (display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    display.clearDisplay();
    display.display();
  }
  
  a2dp_sink.set_avrc_metadata_callback(read_metadata);
  a2dp_sink.set_on_connection_state_changed(connection_state);
  a2dp_sink.start("AudioReceiver");
}

void loop() {
  if (digitalRead(PIN_VOL_UP) == LOW) {
    int vol = a2dp_sink.get_volume() + 5;
    if (vol > 127) vol = 127;
    a2dp_sink.set_volume(vol);
    delay(200);
  }
  if (digitalRead(PIN_VOL_DOWN) == LOW) {
    int vol = a2dp_sink.get_volume() - 5;
    if (vol < 0) vol = 0;
    a2dp_sink.set_volume(vol);
    delay(200);
  }
  if (digitalRead(PIN_PLAY_PAUSE) == LOW) {
    if (a2dp_sink.get_audio_state() == ESP_A2D_AUDIO_STATE_STARTED) {
      a2dp_sink.pause();
    } else {
      a2dp_sink.play();
    }
    delay(300);
  }
  if (digitalRead(PIN_NEXT) == LOW) {
    a2dp_sink.next();
    delay(300);
  }
  if (digitalRead(PIN_PREV) == LOW) {
    a2dp_sink.previous();
    delay(300);
  }
  
  if (millis() - last_update > 1000) {
    update_screen();
    last_update = millis();
  }
}
