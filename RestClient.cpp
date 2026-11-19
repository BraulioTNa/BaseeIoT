
#include "RestClient.h"

RestClient::RestClient(String serverEndpoint)
    : endpoint(serverEndpoint) {
}

bool RestClient::postJson(String jsonPayload) {

    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }

    HTTPClient http;

    http.begin(endpoint);
    http.addHeader("Content-Type", "application/json");

    int responseCode = http.POST(jsonPayload);

    Serial.print("HTTP Response: ");
    Serial.println(responseCode);

    http.end();

    return responseCode >= 200 && responseCode < 300;
}
