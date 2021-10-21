#include "MamStanzaPayload.h"

MamStanzaPayload::MamStanzaPayload()
{
}

const std::string& MamStanzaPayload::getSenderBareJid() const
{
    return senderBareJid_;
}

const std::string& MamStanzaPayload::getId() const
{
    return id_;
}

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

void MamStanzaPayload::setId(const std::string& id)
{
    this->id_ = id;
}

void MamStanzaPayload::setResource(const std::string& rc)
{
    this->recource_ = rc;
}

void MamStanzaPayload::setType(const std::string& type)
{
    this->type_ = type;
}
