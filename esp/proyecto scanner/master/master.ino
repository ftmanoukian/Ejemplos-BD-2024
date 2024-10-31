#include <esp_now.h>
#include <WiFi.h>

// Callback function to handle received messages
void onDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *incomingData, int len) {
    Serial.print("Message from: ");
    for (int i = 0; i < 6; i++) {
        Serial.printf("%02X", recv_info->src_addr[i]);
        if (i < 5) Serial.print(":");
    }
    Serial.print(" | Data: ");
    Serial.write(incomingData, len);  // Print the message content
    Serial.println();
}

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register the receive callback function
    esp_now_register_recv_cb(onDataRecv);

    Serial.println("Central ESP32 is ready to receive messages...");
}

void loop() {
    // The central device waits for incoming messages in the loop
}
