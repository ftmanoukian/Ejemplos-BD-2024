#include <esp_now.h>
#include <WiFi.h>

// MAC address of the central ESP32 (replace with your central ESP32's MAC)
uint8_t centralAddress[] = {0xD4, 0x8A, 0xFC, 0xCF, 0x8F, 0x80}; // Example MAC

// Define message structure
typedef struct struct_message {
    char msg[32];
} struct_message;

// Create a message
struct_message outgoingMessage;

// Callback function for data send status
void onDataSent(const uint8_t *macAddr, esp_now_send_status_t status) {
    Serial.print("Last message send status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
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

    // Register the send callback function
    esp_now_register_send_cb(onDataSent);

    // Register the central ESP32 as a peer
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, centralAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;

    // Add the central ESP32 as a peer
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }

    // Prepare the message
    strcpy(outgoingMessage.msg, "Hello Central ESP32!");
}

void loop() {
    // Send message to central ESP32
    esp_err_t result = esp_now_send(centralAddress, (uint8_t *) &outgoingMessage, sizeof(outgoingMessage));

    if (result == ESP_OK) {
        Serial.println("Message sent successfully");
    } else {
        Serial.println("Error sending the message");
    }

    delay(2000);  // Send every 2 seconds for testing purposes
}
