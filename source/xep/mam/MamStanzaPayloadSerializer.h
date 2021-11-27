#pragma once

#include "MamStanzaPayload.h"
#include <Swiften/Serializer/GenericPayloadSerializer.h>

// (https://swift.im/swiften/guide/#Section-Extending)
class MamStanzaPayloadSerializer : public Swift::GenericPayloadSerializer<MamStanzaPayload>
{
public:
    std::string serializePayload(std::shared_ptr<MamStanzaPayload> payload) const;

private:
    Swift::PayloadSerializerCollection* serializers_;
};
