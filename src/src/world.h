#pragma once

void getGroundPos(Vector3 originalPos, Vector3* outPos);
float distanceBetweenEntities(Entity entity1, Entity entity2);
Ped createPed(const char* model, Vector3 pos);