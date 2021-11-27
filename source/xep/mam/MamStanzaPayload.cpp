#include "MamStanzaPayload.h"

MamStanzaPayload::MamStanzaPayload()
{
}

#if 0
const std::string& MamStanzaPayload::getSenderBareJid() const
{
    return senderBareJid_;
}
#endif

const std::string& MamStanzaPayload::getId() const
{
    return id_;
}

#if 0
const std::string& MamStanzaPayload::getResource() const
{
    return recource_;
}

const std::string& MamStanzaPayload::getType() const
{
    return type_;
}

void MamStanzaPayload::setSenderBareJid(const std::string& sbjid)
{
    this->senderBareJid_ = sbjid;
}
#endif

void MamStanzaPayload::setId(const std::string& id)
{
    this->id_ = id;
}

#if 0
void MamStanzaPayload::setResource(const std::string& rc)
{
    this->recource_ = rc;
}

void MamStanzaPayload::setType(const std::string& type)
{
    this->type_ = type;
}
#endif
