#ifndef __AI_H__
#define __AI_H__

class AI {
public:
	int minimax(int* broad, int isCheck);
	int win(const int* board);
	int computerMove(int* board);

};
#endif // __AI_H__

