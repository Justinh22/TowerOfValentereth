void roomLogic(int &diff, int &rew, int &karma, int adv, Player hero)
{ //  -25 << KARMA >> 25
    int chance;
    if(diff==5)
    {
        if(karma<-10)
        {
            rew = rand() % 3 + 8;
            diff = rand() % 3;
        }
        else if(karma<=10)
        {
            rew = rand() % 5 + 10;
            diff = 0;
        }
        else if(karma>10)
        {
            rew = rand() % 3 + 13;
            diff = 0;
        }
    }
    else if(adv<3)
    {
        {
            chance = rand() % 10 + 1;
            if(karma<-15)
            {
                if(chance<=2)
                {
                    diff = 1;
                }
                else if(chance<=5)
                {
                    diff = 2;
                    karma += 2;
                }
                else if(chance<=10)
                {
                    diff = 3;
                    karma += 4;
                }
                chance = rand() % 10 + 1;
                if(chance<=5)
                {
                    rew = 0;
                    karma += 2;
                }
                else if(chance<=7)
                {
                    rew = 1;
                    karma += 1;
                }
                else if(chance<=9)
                {
                    rew = 1;
                }
                else if(chance<=10)
                {
                    rew = 2;
                    karma -= 1;
                }
            }
            else if(karma<-5)
            {
                if(chance<=3)
                {
                    diff = 1;
                    karma -= 2;
                }
                else if(chance<=8)
                {
                    diff = 2;
                }
                else if(chance<=10)
                {
                    diff = 3;
                    karma += 3;
                }
                chance = rand() % 10 + 1;
                if(chance<=3)
                {
                    rew = 1;
                    karma += 2;
                }
                else if(chance<=5)
                {
                    rew = 1;
                    karma += 1;
                }
                else if(chance<=7)
                {
                    rew = 2;
                }
                else if(chance<=9)
                {
                    rew = 3;
                    karma -= 1;
                }
                else if(chance<=10)
                {
                    rew = 3;
                    karma -= 1;
                }
            }
            else if(karma<=5)
            {
                if(chance<=2)
                {
                    diff = 0;
                    karma -= 2;
                }
                else if(chance<=5)
                {
                    diff = 1;
                }
                else if(chance<=10)
                {
                    diff = 2;
                    karma += 2;
                }
                chance = rand() % 10 + 1;
                if(chance<=2)
                {
                    rew = 1;
                    karma += 2;
                }
                else if(chance<=3)
                {
                    rew = 2;
                    karma += 1;
                }
                else if(chance<=6)
                {
                    rew = 2;
                }
                else if(chance<=8)
                {
                    rew = 3;
                    karma -= 1;
                }
                else if(chance<=10)
                {
                    rew = 3;
                    karma -= 1;
                }
            }
            else if(karma>=15)
            {
                if(chance<=2)
                {
                    diff = 0;
                    karma -= 2;
                }
                else if(chance<=8)
                {
                    diff = 1;
                }
                else if(chance<=10)
                {
                    diff = 2;
                    karma += 2;
                }
                chance = rand() % 10 + 1;
                if(chance<=3)
                {
                    rew = 3;
                    karma += 1;
                }
                else if(chance<=5)
                {
                    rew = 4;
                }
                else if(chance<=7)
                {
                    rew = 4;
                    karma -= 1;
                }
                else if(chance<=9)
                {
                    rew = 5;
                    karma -= 2;
                }
                else if(chance<=10)
                {
                    rew = 6;
                    karma -= 3;
                }
            }
        }
    }
    else if(adv<12)
    {
        chance = rand() % 10 + 1;
        if(karma<-15)
        {
            if(chance<=4)
            {
                diff = 2;
            }
            else if(chance<=6)
            {
                diff = 3;
                karma += 2;
            }
            else if(chance<=9)
            {
                diff = 4;
                karma += 4;
            }
            else if(chance<=10)
            {
                diff = 5;
                karma += 6;
            }
            chance = rand() % 10 + 1;
            if(chance<=5)
            {
                rew = 1;
                karma += 2;
            }
            else if(chance<=7)
            {
                rew = 2;
                karma += 1;
            }
            else if(chance<=9)
            {
                rew = 3;
            }
            else if(chance<=10)
            {
                rew = 3;
                karma -= 1;
            }
        }
        else if(karma<-5)
        {
            if(chance<=3)
            {
                diff = 2;
                karma -= 2;
            }
            else if(chance<=5)
            {
                diff = 2;
            }
            else if(chance<=7)
            {
                diff = 3;
                karma += 2;
            }
            else if(chance<=9)
            {
                diff = 4;
                karma += 4;
            }
            else if(chance<=10)
            {
                diff = 4;
                karma += 6;
            }
            chance = rand() % 10 + 1;
            if(chance<=3)
            {
                rew = 2;
                karma += 2;
            }
            else if(chance<=5)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=7)
            {
                rew = 3;
            }
            else if(chance<=9)
            {
                rew = 4;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 5;
                karma -= 1;
            }
        }
        else if(karma<=5)
        {
            if(chance<=2)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=5)
            {
                diff = 2;
                karma -= 2;
            }
            else if(chance<=7)
            {
                diff = 2;
            }
            else if(chance<=9)
            {
                diff = 3;
                karma += 2;
            }
            else if(chance<=10)
            {
                diff = 4;
                karma += 4;
            }
            chance = rand() % 10 + 1;
            if(chance<=2)
            {
                rew = 2;
                karma += 2;
            }
            else if(chance<=3)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=6)
            {
                rew = 4;
            }
            else if(chance<=8)
            {
                rew = 4;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 5;
                karma -= 1;
            }
        }
        else if(karma>5)
        {
            if(chance<=3)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=6)
            {
                diff = 2;
                karma -= 2;
            }
            else if(chance<=8)
            {
                diff = 2;
            }
            else if(chance<=10)
            {
                diff = 3;
                karma += 2;
            }
            chance = rand() % 10 + 1;
            if(chance<=2)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=4)
            {
                rew = 4;
            }
            else if(chance<=6)
            {
                rew = 5;
                karma -= 1;
            }
            else if(chance<=8)
            {
                rew = 6;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 6;
                karma -= 2;
            }
        }
        else if(karma>15)
        {
            if(chance<=3)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=7)
            {
                diff = 2;
                karma -= 2;
            }
            else if(chance<=10)
            {
                diff = 3;
            }
            chance = rand() % 10 + 1;
            if(chance<=3)
            {
                rew = 4;
                karma += 1;
            }
            else if(chance<=5)
            {
                rew = 5;
            }
            else if(chance<=7)
            {
                rew = 6;
                karma -= 1;
            }
            else if(chance<=9)
            {
                rew = 7;
                karma -= 2;
            }
            else if(chance<=10)
            {
                rew = 8;
                karma -= 3;
            }
        }
        chance = rand() % 17 + 1;
        if(chance==17&&adv>4) //Miniboss Trigger
        {
            diff = 8;
        }
    }
    else
    {
        chance = rand() % 10 + 1;
        if(karma<-15)
        {
            if(chance<=5)
            {
                diff = 3;
                karma += 2;
            }
            else if(chance<=8)
            {
                diff = 4;
                karma += 4;
            }
            else if(chance<=10)
            {
                diff = 5;
                karma += 6;
            }
            chance = rand() % 10 + 1;
            if(chance<=5)
            {
                rew = 1;
                karma += 2;
            }
            else if(chance<=7)
            {
                rew = 2;
                karma += 1;
            }
            else if(chance<=9)
            {
                rew = 3;
            }
            else if(chance<=10)
            {
                rew = 3;
                karma -= 1;
            }
        }
        else if(karma<-5)
        {
            if(chance<=3)
            {
                diff = 2;
                karma -= 2;
            }
            else if(chance<=5)
            {
                diff = 3;
            }
            else if(chance<=7)
            {
                diff = 3;
                karma += 2;
            }
            else if(chance<=9)
            {
                diff = 4;
                karma += 4;
            }
            else if(chance<=10)
            {
                diff = 5;
                karma += 6;
            }
            chance = rand() % 10 + 1;
            if(chance<=3)
            {
                rew = 2;
                karma += 2;
            }
            else if(chance<=5)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=7)
            {
                rew = 3;
            }
            else if(chance<=9)
            {
                rew = 4;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 5;
                karma -= 1;
            }
        }
        else if(karma<=5)
        {
            if(chance<=2)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=5)
            {
                diff = 3;
                karma -= 2;
            }
            else if(chance<=7)
            {
                diff = 3;
            }
            else if(chance<=9)
            {
                diff = 4;
                karma += 2;
            }
            else if(chance<=10)
            {
                diff = 4;
                karma += 4;
            }
            chance = rand() % 10 + 1;
            if(chance<=2)
            {
                rew = 3;
                karma += 2;
            }
            else if(chance<=3)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=6)
            {
                rew = 4;
            }
            else if(chance<=8)
            {
                rew = 4;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 5;
                karma -= 1;
            }
        }
        else if(karma>5)
        {
            if(chance<=3)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=6)
            {
                diff = 3;
                karma -= 2;
            }
            else if(chance<=8)
            {
                diff = 3;
            }
            else if(chance<=10)
            {
                diff = 4;
                karma += 2;
            }
            chance = rand() % 10 + 1;
            if(chance<=2)
            {
                rew = 3;
                karma += 1;
            }
            else if(chance<=4)
            {
                rew = 4;
            }
            else if(chance<=6)
            {
                rew = 5;
                karma -= 1;
            }
            else if(chance<=8)
            {
                rew = 6;
                karma -= 1;
            }
            else if(chance<=10)
            {
                rew = 6;
                karma -= 2;
            }
        }
        else if(karma>15)
        {
            if(chance<=3)
            {
                diff = 0;
                karma -= 4;
            }
            else if(chance<=7)
            {
                diff = 4;
                karma -= 2;
            }
            else if(chance<=10)
            {
                diff = 4;
            }
            chance = rand() % 10 + 1;
            if(chance<=3)
            {
                rew = 4;
                karma += 1;
            }
            else if(chance<=5)
            {
                rew = 5;
            }
            else if(chance<=7)
            {
                rew = 6;
                karma -= 1;
            }
            else if(chance<=9)
            {
                rew = 7;
                karma -= 2;
            }
            else if(chance<=10)
            {
                rew = 8;
                karma -= 3;
            }
        }
        chance = rand() % 15 + 1;
        if(chance==15) //Miniboss Trigger
        {
            diff = 8;
        }
    }
}
