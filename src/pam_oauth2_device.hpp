#ifndef PAM_OAUTH2_DEVICE_HPP
#define PAM_OAUTH2_DEVICE_HPP

#include <string>

class Userinfo
{
public:
    std::string sub,
        username,
        name;
    std::vector<std::string> groups;
};

class DeviceAuthResponse
{
public:
    std::string user_code,
        verification_uri,
        verification_uri_complete,
        device_code;
    std::string get_prompt(const int qr_ecc);
};

void make_authorization_request(const char *client_id,
                                const char *client_secret,
                                const char *scope,
                                const char *device_endpoint,
                                DeviceAuthResponse *response);

void poll_for_token(const char *client_id,
                    const char *client_secret,
                    const char *token_endpoint,
                    const char *device_code,
                    std::string &token);

void get_userinfo(const char *userinfo_endpoint,
                  const char *token,
                  const char *username_attribute,
                  const char *name_attribute,
                  Userinfo *userinfo);

#endif // PAM_OAUTH2_DEVICE_HPP