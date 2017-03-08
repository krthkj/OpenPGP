#include "sigtypes.h"

bool Signature_Type::is_signed_document(const uint8_t sig){
    return ((sig == SIGNATURE_OF_A_BINARY_DOCUMENT) ||
            (sig == SIGNATURE_OF_A_CANONICAL_TEXT_DOCUMENT));
}

bool Signature_Type::is_certification(const uint8_t sig){
    return ((sig == GENERIC_CERTIFICATION_OF_A_USER_ID_AND_PUBLIC_KEY_PACKET)   ||
            (sig == PERSONA_CERTIFICATION_OF_A_USER_ID_AND_PUBLIC_KEY_PACKET)   ||
            (sig == CASUAL_CERTIFICATION_OF_A_USER_ID_AND_PUBLIC_KEY_PACKET)    ||
            (sig == POSITIVE_CERTIFICATION_OF_A_USER_ID_AND_PUBLIC_KEY_PACKET));
}