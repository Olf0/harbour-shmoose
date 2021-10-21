#include "MamStanzaPayloadParser.h"

#include <iostream>
#include <QString>

MamStanzaPayloadParser::MamStanzaPayloadParser()
{
}


#if 0
<message xmlns="jabber:client" to="s@jabber.ccc.de/shmooseDesktop" from="99@conference.jabber.ccc.de">
 <result xmlns="urn:xmpp:mam:2" id="1634756341939294">
  <forwarded xmlns="urn:xmpp:forward:0">
   <message xmlns="jabber:client" from="99@conference.jabber.ccc.de/b(at)jabber.de" type="groupchat" id="ee5df22b-6867-4794-a0de-99b256fd09c5">
    <x xmlns="http://jabber.org/protocol/muc#user">
     <item jid="b@jabber.de/shmoose"></item>
    </x>
    <archived xmlns="urn:xmpp:mam:tmp" by="99@conference.jabber.ccc.de" id="1634756341939294"></archived>
    <stanza-id xmlns="urn:xmpp:sid:0" by="99@conference.jabber.ccc.de" id="1634756341939294"></stanza-id>
    <request xmlns="urn:xmpp:receipts"></request>
    <markable xmlns="urn:xmpp:chat-markers:0"></markable>
    <body>foo</body>
   </message>
   <delay xmlns="urn:xmpp:delay" from="conference.jabber.ccc.de" stamp="2021-10-20T18:59:01.939294Z"></delay>
  </forwarded>
 </result>
</message>
#endif

#if 0
        <message xmlns="jabber:client" to="s@jabber.ccc.de/shmooseDesktop" from="s@jabber.ccc.de">
         <result xmlns="urn:xmpp:mam:2" id="1634068570466306">
          <forwarded xmlns="urn:xmpp:forward:0">
           <message xmlns="jabber:client" to="s@jabber.ccc.de" from="s@jabber-germany.de/shmoose" type="chat" id="6043f343-a192-435f-b67b-3bd7f2035799">
            <archived xmlns="urn:xmpp:mam:tmp" by="s@jabber.ccc.de" id="1634068570466306"></archived>
            <stanza-id xmlns="urn:xmpp:sid:0" by="s@jabber.ccc.de" id="1634068570466306"></stanza-id>
            <x xmlns="jabber:x:oob">
             <url>aesgcm://jabber-germany.de:5281/upload/iTkykb82fxseCzIa/1634069d95b050d5944488c27e0891b62</url>
            </x>
            <request xmlns="urn:xmpp:receipts"></request>
            <markable xmlns="urn:xmpp:chat-markers:0"></markable>
            <encrypted xmlns="eu.siacs.conversations.axolotl">
             <header sid="675380023">
              <key rid="283606956">MwgoEiEYFw6ldaeNinevAot/aFwgIwAQ==</key>
              <key rid="971094933">MwohBWvBIFTSqQ78BIz55PzF/Fc+x8sOYvGk=</key>
              <iv>pqwKwtC9</iv>
             </header>
             <payload>SaG13TSFT43OJUhpGTgLxM/esWP6S/RvTwWK7jFJaQ3RKaelf0=</payload>
            </encrypted>
            <encryption xmlns="urn:xmpp:eme:0" namespace="eu.siacs.conversations.axolotl" name="OMEMO"></encryption>
            <store xmlns="urn:xmpp:hints"></store>
           </message>
           <delay xmlns="urn:xmpp:delay" from="jabber.ccc.de" stamp="2021-10-12T19:56:10.466306Z"></delay>
          </forwarded>
         </result>
        </message>
#endif

void MamStanzaPayloadParser::handleStartElement(const std::string& element, const std::string& ns, const Swift::AttributeMap& attributes)
{
    std::cout << "################# MamStanzaPayloadParser::handleStartElement ###############" << std::endl;

    if (level_ == 2) // message metadata
    {
        //getPayloadInternal()->setBy(attributes.getAttribute("by"));
        //getPayloadInternal()->setId(attributes.getAttribute("id"));
        auto id = attributes.getAttribute("id");
        std::cout << "id: " << id  << std::endl;
        getPayloadInternal()->setId(attributes.getAttribute("id"));

        auto from = attributes.getAttribute("from");
        std::cout << "from: " << from  << std::endl;

        auto senderBareJid = Swift::JID(from).toBare().toString();
        auto resource = Swift::JID(from).getResource();
        getPayloadInternal()->setSenderBareJid(attributes.getAttribute(senderBareJid));
        getPayloadInternal()->setResource(attributes.getAttribute(resource));

        std::cout << "from bare: " << senderBareJid.toStdString()  << std::endl;
        std::cout << "from res: " << resource.toStdString()  << std::endl;

        std::cout << "type: " << attributes.getAttribute("type") << std::endl;
    }

    if (level_ == 2) // body | encrypted
    {
        if (element.compare("encrypted") == 0)
        {

        }
        else if (element.compare("body") == 0)
        {

        }
    }

    level_++;
}

void MamStanzaPayloadParser::handleEndElement(const std::string& /* element */, const std::string& /* ns */)
{
    level_--;
}

void MamStanzaPayloadParser::handleCharacterData(const std::string& /* data */)
{
}
