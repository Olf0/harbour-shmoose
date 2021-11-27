#pragma once

#include <Swiften/Swiften.h>

// See https://swift.im/swiften/guide/#Section-Extending
class MamStanzaPayload : public Swift::Payload
{
public:
    MamStanzaPayload();

    const std::string& getId() const;
#if 0
    const std::string& getSenderBareJid() const;
    const std::string& getResource() const;
    const std::string& getType() const;
#endif

    void setFwdPayload(std::shared_ptr<Swift::Payload> payload) { fwdPayload_ = payload; }
    const std::shared_ptr<Swift::Payload>& getFwdPayload() const { return fwdPayload_; }

    void setStanza(std::shared_ptr<Swift::Stanza> stanza) { stanza_ = stanza; }
    const std::shared_ptr<Swift::Stanza>& getStanza() const { return stanza_; }


    void setId(const std::string& id);
#if 0
    void setSenderBareJid(const std::string& by);
    void setResource(const std::string& rc);
    void setType(const std::string& type);
#endif
private:
    std::string id_{};
    std::shared_ptr<Swift::Stanza> stanza_;
#if 0
    std::string senderBareJid_{};
    std::string recource_{};
    std::string type_{};
#endif
    std::shared_ptr<Swift::Payload> payload_;

    std::shared_ptr<Swift::Payload> fwdPayload_;

    int direction{0};
};
