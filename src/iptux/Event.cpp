#include "config.h"
#include "Event.h"

namespace iptux {

NewPalOnlineEvent::NewPalOnlineEvent(PalInfo *palInfo)
  : Event(),
    palInfo(palInfo) {}

EventType NewPalOnlineEvent::getType() const {
  return EventType ::NEW_PAL_ONLINE;
}

const PalInfo* NewPalOnlineEvent::getPalInfo() const {
  return palInfo;
}

NewMessageEvent::NewMessageEvent(MsgPara&& msgPara)
  : Event(),
    msgPara(msgPara) {}

EventType NewMessageEvent::getType() const {
  return EventType ::NEW_MESSAGE;
}

}
