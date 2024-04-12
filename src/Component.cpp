#include "Component.h"
#include "GameObject.h"

Component::Component() : associated{ *(new GameObject()) } {}

Component::Component(GameObject& go) : associated(go) {}

Component::~Component() {}