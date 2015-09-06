/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */

#include <oscVariables.h>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/util/XMLString.hpp>
#include <cstdlib>

namespace OpenScenario {

template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<int>::getType(){return oscMemberValue::INT;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<unsigned int>::getType(){return oscMemberValue::UINT;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<short>::getType(){return oscMemberValue::SHORT;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<unsigned short>::getType(){return oscMemberValue::USHORT;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<std::string>::getType(){return oscMemberValue::STRING;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<double>::getType(){return oscMemberValue::DOUBLE;};
template<>
OPENSCENARIOEXPORT oscMemberValue::MemberTypes oscVariable<time_t>::getType(){return oscMemberValue::DATE_TIME;};


template<>
OPENSCENARIOEXPORT bool oscValue<int>::initialize(xercesc::DOMAttr *attribute){value = atoi(xercesc::XMLString::transcode(attribute->getValue())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<unsigned int>::initialize(xercesc::DOMAttr *attribute){value = std::stol(xercesc::XMLString::transcode(attribute->getValue())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<short>::initialize(xercesc::DOMAttr *attribute){value = atoi(xercesc::XMLString::transcode(attribute->getValue())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<unsigned short>::initialize(xercesc::DOMAttr *attribute){value = atoi(xercesc::XMLString::transcode(attribute->getValue())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<std::string>::initialize(xercesc::DOMAttr *attribute){value = xercesc::XMLString::transcode(attribute->getValue()); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<double>::initialize(xercesc::DOMAttr *attribute){value = atof(xercesc::XMLString::transcode(attribute->getValue())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<time_t>::initialize(xercesc::DOMAttr *attribute){ return false;};

template<>
OPENSCENARIOEXPORT bool oscValue<int>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){char buf[100]; sprintf(buf, "%d", value); currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(buf)); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<unsigned int>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){char buf[100]; sprintf(buf, "%u", value); currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(buf)); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<short>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){char buf[100]; sprintf(buf, "%hd",value); currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(buf)); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<unsigned short>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){char buf[100]; sprintf(buf, "%hu", value); currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(buf)); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<std::string>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(value.c_str())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<double>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(std::to_string(value).c_str())); return true;};
template<>
OPENSCENARIOEXPORT bool oscValue<time_t>::writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *, const char *name){char buf[100]; sprintf(buf, "%ld", (long)value); currentElement->setAttribute(xercesc::XMLString::transcode(name), xercesc::XMLString::transcode(buf)); return true;};

}