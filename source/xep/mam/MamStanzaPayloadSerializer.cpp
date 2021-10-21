#include "MamStanzaPayloadSerializer.h"

std::string MamStanzaPayloadSerializer::serializePayload(std::shared_ptr<MamStanzaPayload> payload) const
{
    Swift::XMLElement element("result", "urn:xmpp:mam:2");
    element.setAttribute("id", payload->getId());
    element.setAttribute("by", payload->getBy());
    return element.serialize();
}
