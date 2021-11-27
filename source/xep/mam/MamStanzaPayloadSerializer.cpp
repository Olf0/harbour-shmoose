#include "MamStanzaPayloadSerializer.h"

std::string MamStanzaPayloadSerializer::serializePayload(std::shared_ptr<MamStanzaPayload> payload) const
{
    if (!payload) {
        return "";
    }

    Swift::XMLElement element("result", "urn:xmpp:mam:2");

    if (! payload->getId().empty()) {
        element.setAttribute("id", payload->getId());
    }

    if (payload->getFwdPayload())
    {
        // FIXME add the fwdpaylod to the element?
         // all needed elements are there :-)!
    }

    if (payload->getStanza()) { /* find out what type of stanza we are dealing with and branch into the correct serializer*/
        std::shared_ptr<Swift::IQ> iq;
        std::shared_ptr<Swift::Message> message;
        std::shared_ptr<Swift::Presence> presence;
        const std::string ns = "jabber:client";
        if ((iq = std::dynamic_pointer_cast<Swift::IQ>(payload->getStanza()))) {
            element.addNode(std::make_shared<Swift::XMLRawTextNode>(safeByteArrayToString(Swift::IQSerializer(serializers_).serialize(iq, ns))));
        } else if ((message = std::dynamic_pointer_cast<Swift::Message>(payload->getStanza()))) {
            element.addNode(std::make_shared<Swift::XMLRawTextNode>(safeByteArrayToString(Swift::MessageSerializer(serializers_).serialize(message, ns))));
        } else if ((presence = std::dynamic_pointer_cast<Swift::Presence>(payload->getStanza()))) {
            element.addNode(std::make_shared<Swift::XMLRawTextNode>(safeByteArrayToString(Swift::PresenceSerializer(serializers_).serialize(presence, ns))));
        }
    }

    return element.serialize();



#if 0
    Swift::XMLElement element("result", "urn:xmpp:mam:2");
    element.setAttribute("id", payload->getId());
    return element.serialize();
#endif


#if 0
    if (!payload) {
        return "";
    }

    XMLElement element("forwarded", "urn:xmpp:forward:0");

    if (payload->getDelay()) {
        element.addNode(std::make_shared<XMLRawTextNode>(DelaySerializer().serialize(payload->getDelay())));
    }

    if (payload->getStanza()) { /* find out what type of stanza we are dealing with and branch into the correct serializer*/
        std::shared_ptr<IQ> iq;
        std::shared_ptr<Message> message;
        std::shared_ptr<Presence> presence;
        const std::string ns = "jabber:client";
        if ((iq = std::dynamic_pointer_cast<IQ>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(IQSerializer(serializers_).serialize(iq, ns))));
        } else if ((message = std::dynamic_pointer_cast<Message>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(MessageSerializer(serializers_).serialize(message, ns))));
        } else if ((presence = std::dynamic_pointer_cast<Presence>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(PresenceSerializer(serializers_).serialize(presence, ns))));
        }
    }

    return element.serialize();
#endif

}
