#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "json.hpp"

extern "C" {
#include "tls-client.h"
}

std::vector<std::string> readTokensFromFile(const std::string& filename) {
    std::vector<std::string> tokens;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tokens;
    }

    std::string token;
    while (file >> token) {
        tokens.push_back(token);
    }

    file.close();
    return tokens;
}

char* getjson(const char* val1, const char* val2) {
    nlohmann::json data;
    data["tlsClientIdentifier"] = "chrome_114";
    data["followRedirects"] = false;
    data["insecureSkipVerify"] = false;
    data["withoutCookieJar"] = false;
    data["withDefaultCookieJar"] = false;
    data["forceHttp1"] = false;
    data["withDebug"] = false;
    data["withRandomTLSExtensionOrder"] = false;
    data["isByteResponse"] = false;
    data["isByteRequest"] = false;
    data["catchPanics"] = false;
    data["additionalDecode"] = "";
    data["timeoutSeconds"] = 30;
    data["timeoutMilliseconds"] = 0;
    data["certificatePinningHosts"] = nlohmann::json::object();
    data["proxyUrl"] = "";
    data["isRotatingProxy"] = false;

    nlohmann::json headers;
    headers["authority"] = "discord.com";
    headers["accept"] = "*/*";
    headers["accept-language"] = "pl-PL,pl;q\u003d0.9,en-US;q\u003d0.8,en;q\u003d0.7";
    headers["authorization"] = val1;
    headers["content-type"] = "application/json";
    headers["cookie"] = "__dcfduid\u003d394d5cc207bd11eeb136fab7c0b196fd; __sdcfduid\u003d394d5cc207bd11eeb136fab7c0b196fd69c6af05266b4cf21871635df4ddf33ed9766eee9eec7b3e1f3c0de796f645b1; OptanonAlertBoxClosed\u003d2023-06-11T09:41:11.883Z; cf_clearance\u003dk8.tEbDkRl5ZuyS945sbHJhHWy8ULz22QvUBAEug5BM-1689704245-0-0.2.1689704245; __cfruid\u003d576274820ce3f7f2cd79b85c978acae7f58e827c-1689777932; OptanonConsent\u003disIABGlobal\u003dfalse\u0026datestamp\u003dWed+Jul+19+2023+16%3A45%3A34+GMT%2B0200+(czas+%C5%9Brodkowoeuropejski+letni)\u0026version\u003d6.33.0\u0026hosts\u003d\u0026landingPath\u003dNotLandingPage\u0026groups\u003dC0001%3A1%2CC0002%3A1%2CC0003%3A1\u0026geolocation\u003dPL%3B14\u0026AwaitingReconsent\u003dfalse; locale\u003dpl";
    headers["origin"] = "https://discord.com";
    headers["pragma"] = "no-cache";
    headers["referer"] = "https://discord.com/channels/987435720404787230/987435720404787233";
    headers["sec-ch-ua"] = "\"Not.A/Brand\";v\u003d\"8\", \"Chromium\";v\u003d\"114\", \"Google Chrome\";v\u003d\"114\"";
    headers["sec-ch-ua-mobile"] = "?0";
    headers["sec-ch-ua-platform"] = "\"Windows\"";
    headers["sec-fetch-dest"] = "empty";
    headers["sec-fetch-mode"] = "cors";
    headers["sec-fetch-site"] = "same-origin";
    headers["user-agent"] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36";
    headers["x-content-properties"] = "eyJsb2NhdGlvbiI6IkpvaW4gR3VpbGQiLCJsb2NhdGlvbl9ndWlsZF9pZCI6IjgyMDcyMzg2ODM0NzUzMTI2NCIsImxvY2F0aW9uX2NoYW5uZWxfaWQiOiI4NDIwOTQ1NzIwNjk5NzgxMTIiLCJsb2NhdGlvbl9jaGFubmVsX3R5cGUiOjB9";
    headers["x-debug-options"] = "bugReporterEnabled";
    headers["x-discord-locale"] = "pl";
    headers["x-discord-timezone"] = "Europe/Warsaw";
    headers["x-super-properties"] = "eyJvcyI6IldpbmRvd3MiLCJicm93c2VyIjoiQ2hyb21lIiwiZGV2aWNlIjoiIiwic3lzdGVtX2xvY2FsZSI6InBsLVBMIiwiYnJvd3Nlcl91c2VyX2FnZW50IjoiTW96aWxsYS81LjAgKFdpbmRvd3MgTlQgMTAuMDsgV2luNjQ7IHg2NCkgQXBwbGVXZWJLaXQvNTM3LjM2IChLSFRNTCwgbGlrZSBHZWNrbykgQ2hyb21lLzExNC4wLjAuMCBTYWZhcmkvNTM3LjM2IiwiYnJvd3Nlcl92ZXJzaW9uIjoiMTE0LjAuMC4wIiwib3NfdmVyc2lvbiI6IjEwIiwicmVmZXJyZXIiOiIiLCJyZWZlcnJpbmdfZG9tYWluIjoiIiwicmVmZXJyZXJfY3VycmVudCI6IiIsInJlZmVycmluZ19kb21haW5fY3VycmVudCI6IiIsInJlbGVhc2VfY2hhbm5lbCI6InN0YWJsZSIsImNsaWVudF9idWlsZF9udW1iZXIiOjIxMzY5NSwiY2xpZW50X2V2ZW50X3NvdXJjZSI6bnVsbH0\u003d";

    data["headers"] = headers;
    data["headerOrder"] = {"accept", "user-agent", "accept-encoding", "accept-language"};
    data["requestUrl"] = val2;
    data["requestMethod"] = "POST";
    data["requestBody"] = "{}";
    data["requestCookies"] = nlohmann::json::array();

    std::string jsonStr = data.dump();

    char* result = new char[jsonStr.length() + 1];
    strcpy(result, jsonStr.c_str());

    return result;
}



 

int main() {
    const std::string filename = "tokens.txt";
    std::vector<std::string> tokens = readTokensFromFile(filename);
    std::cout << "Discord c++ joinner\n";
    std::string i;
    std::cout << "Invite (without discord.gg/): ";
    std::cin >> i;

       std::string invite = "https://discord.com/api/v9/invites/" + i;
       for (const std::string& token : tokens) {
       
	   char* json = getjson(token.c_str(),invite.c_str());
        std::string response = request(json);
		
	
		
		
        if (response.find("\"status\":200") != std::string::npos) {
        std::cout << "Joinned " << token << std::endl;
        } else {
        std::cout << "Failed " << token << std::endl;
        }
        delete[] json;
    }
}
