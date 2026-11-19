
#ifndef REST_CLIENT_H
#define REST_CLIENT_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

class RestClient {
private:
    String endpoint;

public:
    explicit RestClient(String serverEndpoint);

    bool postJson(String jsonPayload);
};

#endif
