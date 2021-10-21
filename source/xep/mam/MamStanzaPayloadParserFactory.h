#pragma once

#include "MamStanzaPayloadParser.h"

// (https://swift.im/swiften/guide/#Section-Extending)
class MamStanzaPayloadParserFactory : public Swift::GenericPayloadParserFactory<MamStanzaPayloadParser>
{
public:
    MamStanzaPayloadParserFactory();
};
