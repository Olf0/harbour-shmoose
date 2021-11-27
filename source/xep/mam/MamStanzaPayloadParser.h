#pragma once

#include "MamStanzaPayload.h"

// (https://swift.im/swiften/guide/#Section-Extending)
class MamStanzaPayloadParser : public Swift::GenericPayloadParser<MamStanzaPayload>
{
public:
    MamStanzaPayloadParser();

    void handleStartElement(const std::string& element, const std::string& ns, const Swift::AttributeMap& attributes);
    void handleEndElement(const std::string& element, const std::string& ns);
    void handleCharacterData(const std::string& data);

    enum Level {
        TopLevel = 0,
        PayloadLevel = 1
    };


private:
    int level_{0};

    Swift::PayloadParserFactoryCollection* factories_;
    std::shared_ptr<Swift::StanzaParser> childParser_;
    std::shared_ptr<Swift::DelayParser> delayParser_;
    std::shared_ptr<Swift::ForwardedParser> fwdParser_;

};
