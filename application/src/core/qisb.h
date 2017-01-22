#ifndef QISB_H
#define QISB_H

//
// Properties
//

// Entities properties
#define ISB_PROPERTY_ENTITY_UID ":isb:property:uid"
#define ISB_PROPERTY_ENTITY_ID ":isb:property:id"

// Items properties
#define ISB_PROPERTY_ITEM_TOP ":isb:property:uid"
#define ISB_PROPERTY_ITEM_LEFT ":isb:property:uid"
#define ISB_PROPERTY_ITEM_WIDTH ":isb:property:uid"
#define ISB_PROPERTY_ITEM_HEIGHT ":isb:property:uid"

//
// Settings
//

#define ISB_SETTING_UNDO ":isb:setting:undo"
#define ISB_SETTING_NOTIFY ":isb:setting:notify"
#define ISB_SETTING_CODE ":isb:setting:code"

//
// Values
//

#define ISB_VALUE_TRUE "1"
#define ISB_VALUE_FALSE "0"

//
// Defaults
//

// Items defaults
#define ISB_DEFAULT_ITEM_PADDING 4

class Qisb
{
public:
  enum QisbType
  {
    Sequence    = 1,
    Dimension   = 2,
    Panel       = 3,
    Object      = 4,
    Link        = 5,

    NoType      = 0
  };
};

typedef Qisb::QisbType QisbType;

#endif // QISB_H
