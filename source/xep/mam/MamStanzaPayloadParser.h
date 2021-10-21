#pragma once

#include "MamStanzaPayload.h"

// (https://swift.im/swiften/guide/#Section-Extending)
class MamStanzaPayloadParser : public Swift::GenericPayloadParser<MamStanzaPayload>
{
public:
    MamStanzaPayloadParser();

    void handleStartElement(const std::string& element, const std::string& ns, const Swift::AttributeMap& attributes);
    void handleEndElement(const std::string& /* element */, const std::string& /* ns */);
    void handleCharacterData(const std::string& /* data */);

private:
    int level_{0};
};
