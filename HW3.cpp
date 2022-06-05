#include <iostream>
#include <vector>
#include "chess.h"
using namespace std;
using namespace chess;

bool chess::in_scope(posion p)
{
    return p.column >= 1 && p.column <= 8 && p.row >= 1 &&  p.row <= 8;
}

void chess::show_moves(posion p)
{
    cout << "All available moves:\n";
    vector<posion> vp = {
        move_two_left_one_up(p),
        move_one_left_two_up(p),
        move_one_right_two_up(p),
        move_two_right_one_up(p),
        move_two_right_one_down(p),
        move_one_right_two_down(p),
        move_two_left_one_down(p),
        move_one_left_two_down(p)
    };

    for (posion x : vp)
        if (in_scope(x))
            cout << "(" << x.column << "," << x.row << ")\n";
}


posion chess::move_two_left_one_up(posion p)
{
    posion pn = {.column=p.column-2, .row=p.row+1};
    return pn;
}

posion chess::move_one_left_two_up(posion p)
{
    posion pn = {.column=p.column-1, .row=p.row+2};
    return pn;
}

posion chess::move_one_right_two_up(posion p)
{
    posion pn = {.column=p.column+1, .row=p.row+2};
    return pn;
}

posion chess::move_two_right_one_up(posion p)
{
    posion pn = {.column=p.column+2, .row=p.row+1};
    return pn;
}

posion chess::move_two_right_one_down(posion p)
{
    posion pn = {.column=p.column+2, .row=p.row-1};
    return pn;
}

posion chess::move_one_right_two_down(posion p)
{
    posion pn = {.column=p.column+1, .row=p.row-2};
    return pn;
}

posion chess::move_one_left_two_down(posion p)
{
    posion pn = {.column=p.column-1, .row=p.row-2};
    return pn;
}

posion chess::move_two_left_one_down(posion p)
{
    posion pn = {.column=p.column-2, .row=p.row-1};
    return pn;
}
© 