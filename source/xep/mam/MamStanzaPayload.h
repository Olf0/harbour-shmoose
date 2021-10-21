#pragma once

#include <Swiften/Swiften.h>

// See https://swift.im/swiften/guide/#Section-Extending
class MamStanzaPayload : public Swift::Payload
{
public:
    MamStanzaPayload();

    const std::string& getId() const;
    const std::string& getSenderBareJid() const;
    const std::string& getResource() const;
    const std::string& getType() const;

    void setId(const std::string& id);
    void setSenderBareJid(const std::string& by);
    void setResource(const std::string& rc);
    void setType(const std::string& type);

private:
    std::string id_{};

    std::string senderBareJid_{};
    std::string recource_{};
    std::string type_{};

    int direction{0};
};
