#pragma once

enum GallowsLeverMode {
	Push,
	Pull
};

class Gallows 
{
private:
	Vector3 leverPosition;
	vector<Vector3> trapdoorPositions;
	int trapdoorModel;
	char* trapdoorAnimation;
	GallowsLeverMode leverMode;

public:
	static Gallows* fromPosition(Vector3 position);

	Gallows(Vector3 leverPosition, vector<Vector3> trapdoorPositions, int trapdoorModel, char* trapdoorAnimation, GallowsLeverMode leverMode = Push);
	void pullLever(Ped executioner);
	void reset(Ped executioner);
	bool isLeverPulled();
	GallowsLeverMode getLeverMode();
	Vector3 getPosition();

protected:
	virtual vector<Entity> getTrapdoors();
	virtual Entity getLever();
	virtual void playTrapdoorAnimation(Entity trapdoor);
	virtual void playLeverAnimation(Entity lever);
	virtual void playLeverPullAnimation(Ped executioner);
	virtual void resetLever(Entity lever);
	virtual void resetTrapdoor(Entity trapdoor);
	virtual char* getLeverAnimationName();
	virtual char* getLeverPulllAnimationName();
	virtual int getTrapdoorModel();

private: 
	void getToLever(Entity executioner);
};

#include "StDanisGallows.h"