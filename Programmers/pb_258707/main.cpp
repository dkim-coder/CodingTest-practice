#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#if 0
struct node
{
    vector<int> myCards;
    int myCoin;
    int round;
    int pos;
};

vector<node> returnCase(node inNode, int targetNum)
{
    vector<node> res;

    for (int i = 0; i < inNode.myCards.size() - 1; i++)
    {
        for (int j = i + 1; j < inNode.myCards.size(); j++)
        {
            if (inNode.myCards[i] + inNode.myCards[j] == targetNum)
            {
                node tmpNode;
                tmpNode.round = inNode.round;
                tmpNode.myCoin = inNode.myCoin;
                tmpNode.pos = inNode.pos;
                for (int k = 0; k < inNode.myCards.size(); k++)
                {
                    if (k != i && k != j)
                        tmpNode.myCards.push_back(inNode.myCards[k]);
                }
                res.push_back(tmpNode);
            }
        }
    }

    return res;
}

int solution(int coin, vector<int> cards)
{
    int res = 0;
    queue<node> q;
    node firstNode;
    int n = cards.size();
    for (int i = 0; i < n / 3; i++)
    {
        firstNode.myCards.push_back(cards[i]);
    }
    firstNode.myCoin = coin;
    firstNode.round = 1;
    firstNode.pos = n / 3;
    q.push(firstNode);

    // BFS
    while (!q.empty())
    {
        node curNode = q.front();
        q.pop();

        if (curNode.round > res)
            res = curNode.round;

        if (curNode.pos >= n)
            continue;

        for (int i = 0; i < 4; i++)
        {
            node tmpNode = curNode;
            tmpNode.round += 1;
            if (i == 0)
            {
                tmpNode.myCards.push_back(cards[tmpNode.pos]);
                tmpNode.myCards.push_back(cards[tmpNode.pos + 1]);
                tmpNode.myCoin -= 2;
            }
            else if (i == 1)
            {
                tmpNode.myCards.push_back(cards[tmpNode.pos]);
                tmpNode.myCoin -= 1;
            }
            else if (i == 2)
            {
                tmpNode.myCards.push_back(cards[tmpNode.pos + 1]);
                tmpNode.myCoin -= 1;
            }
            tmpNode.pos += 2;

            if (tmpNode.myCoin < 0)
                continue;

            if (tmpNode.myCards.size() >= 2)
            {
                vector<node> allNode = returnCase(tmpNode, n + 1);
                for (auto a : allNode)
                    q.push(a);
            }
        }
    }

    return res;
}
#endif

int solution(int coin, vector<int> cards)
{
    int res = 1;
    int n = cards.size();
    int startNum = n / 3;
    int combiNum = 0;
    int specialCase = 0;

    // 처음 받은 카드로 n + 1 만들 수 있는 개수
    for (int i = 0; i < startNum - 1; i++)
    {
        for (int j = i + 1; j < startNum; j++)
        {
            if (cards[i] + cards[j] == n + 1)
            {
                combiNum++;
                break;
            }
        }
    }

    for (int i = startNum; i < n; i += 2)   // 2개씩 추가 되는 부분
    {
        for (int j = 0; j < i; j++) // 현재까지 추가한 부분까지는 체크 해야 하니까
        {
            if (j < startNum)
            {
                if (cards[i] + cards[j] == n + 1 && coin >= 1)
                {
                    combiNum += 1;
                    coin -= 1;
                }
                if(cards[i + 1] + cards[j] == n + 1 && coin >= 1)   // 추가되는 두 번째 카드 체크
                {
                    combiNum += 1;
                    coin -= 1;
                }
            }else{
                if(cards[i] + cards[j] == n + 1)
                {
                    specialCase += 1;
                }
                if(cards[i + 1] + cards[j] == n + 1)
                {
                    specialCase += 1;
                }
            }
        }
        if(cards[i] + cards[i + 1] == n + 1)
        {
            specialCase += 1;
        }
        if(combiNum > 0)
        {
            res += 1;
            combiNum -= 1;
        }else
        {
            if(specialCase > 0 && coin >= 2)
            {
                specialCase -=1;
                res += 1;
                coin -=2;
            }else
            {
                break;
            }
        }
    }

    return res;
}

int main()
{
    int coin = 2;
    vector<int> cards = {5, 8, 1, 2, 9, 4, 12, 11, 3, 10, 6, 7};

    cout << solution(coin, cards) << endl;

    return EXIT_SUCCESS;
}