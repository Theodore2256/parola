#include <iostream>
#include <string.h>
#include <ctype.h>
#include <vector>

using namespace std;


class  Policy
{
public:
bool  isChecked;
  virtual void check( const string parola)=0;
public:
  bool getCheck  () const
  {
      return isChecked;
  }
};

class LengthPolicy : public Policy
        {
protected:
    uint16_t minLength ;
    uint16_t maxLength;
public:
            LengthPolicy(uint16_t min)
            {
                minLength=min;
                maxLength=255;
            }
    LengthPolicy(uint16_t min,uint16_t max)
    {
        minLength=min;
        maxLength=max;
    }
    void check( const string parola) override
    {
                if(parola.size()>=minLength || (parola.size()<=maxLength))
                    isChecked= true;
                else
                    isChecked= false;
    }
};
 class ClassPolicy: public Policy {
     uint16_t  minClassCount;
 public:
      ClassPolicy (uint16_t min)
      {
          minClassCount=min;
      }
     void check( const string parola)
     {
          int k=0,k1=0,k2=0,k3=0;
         for (int i = 0; i < parola.size(); ++i)
         {
             if (islower(parola[i]))
                 k=1;
             if (isupper(parola[i]))
                 k1=1;
             if(isdigit(parola[i]))
                 k2=1;
             if(ispunct(parola[i]))
                 k3=1;
         }
         if(k+k1+k2+k3==minClassCount)
             isChecked= true;
         else isChecked= false;
     }
 };
class IncludePolicy: public Policy {
    char characterType;

public:

    explicit IncludePolicy(char x)
    {
        characterType = x;
    }
            void check(const std::string parola) override
            {  bool ok= false;
                if (islower(characterType))
                {
                    for (int i = 0; i < parola.size(); ++i)
                    {
                        if (1 == islower(parola[i]))
                            ok = true;
                    }
                }
                if (isupper(characterType))
                {
                    for (int i = 0; i < parola.size(); ++i)
                    {
                        if (isupper(characterType) == isupper(parola[i]))
                            ok = true;
                    }
                }
                if (isdigit(characterType))
                {
                    for (int i = 0; i < parola.size(); ++i)
                    {
                        if (isdigit(characterType) == isdigit(parola[i]))
                            ok = true;
                    }
                }
                if (ispunct(characterType))
                {
                    for (int i = 0; i < parola.size(); ++i)
                    {
                        if (ispunct(characterType) == ispunct(parola[i]))
                            ok = true;
                    }
                }


                if(ok)
                    isChecked=true;
                else isChecked = false;
            }


};
class NotIncludePolicy: public Policy {
    char characterType;

public:

    explicit NotIncludePolicy(char x)
    {
        characterType = x;
    }
    void check(const std::string parola) override
    {  bool ok= false;
        if (islower(characterType))
        {
            for (int i = 0; i < parola.size(); ++i)
            {
                if (1 == islower(parola[i]))
                    ok = true;
            }
        }
        if (isupper(characterType))
        {
            for (int i = 0; i < parola.size(); ++i)
            {
                if (isupper(characterType) == isupper(parola[i]))
                    ok = true;
            }
        }
        if (isdigit(characterType))
        {
            for (int i = 0; i < parola.size(); ++i)
            {
                if (isdigit(characterType) == isdigit(parola[i]))
                    ok = true;
            }
        }
        if (ispunct(characterType))
        {
            for (int i = 0; i < parola.size(); ++i)
            {
                if (ispunct(characterType) == ispunct(parola[i]))
                    ok = true;
            }
        }


        if(ok==0)
            isChecked=true;
        else isChecked = false;
    }


};
class RepetitionPolicy : public Policy
{

    uint16_t maxCount;
public:
    void check(const std::string parola) override
    { int k=0;
        for (int i = 0; i < parola.size(); ++i)
        {
        if(parola[i]==parola[i+1])
            k++;
        }
        if(k<=maxCount)
            isChecked= true;
        else isChecked= false;
    }


    RepetitionPolicy(uint16_t x)
    {
        maxCount=x;
    }
};
class ConsecutivePolicy : public Policy
{
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t x)
    {
        maxCount=x;
    }

    void check(const std::string parola) override
    {
        uint16_t k1=0,k2=0,k3=0,k4=0;
        for (int i = 0; i < parola.size(); ++i)
        {  char carc=parola[i];
            if(isupper(parola[i]))
            {
                for (int j = i; j <=maxCount ; ++j)
                {
                    if (isupper(parola[j])== isupper(carc))
                        k1++;
                }
            }
            if(islower(parola[i]))
            {
                for (int j = i; j <=maxCount ; ++j)
                {
                    if (islower(parola[j])== islower(carc))
                        k2++;
                }
            }
            if(isdigit(parola[i]))
            {
                for (int j = i; j <=maxCount ; ++j)
                {
                    if (isdigit(parola[j])== isdigit(carc))
                        k3++;
                }
            }
            if(ispunct(parola[i]))
            {
                for (int j = i; j <=maxCount ; ++j)
                {
                    if (ispunct(parola[j])== ispunct(carc))
                        k4++;
                }
            }
        }

        if(k1 && k2&& k3&& k4 <maxCount)
            isChecked= true;
        else isChecked= false;
    }

};

  string checkPassword(string parola , vector <Policy *> cerinte )
 { int ok=0;
     for (int i = 0; i < cerinte.size(); ++i)
     {
         cerinte[i]->check(parola);
         if(cerinte[i]->getCheck()==1)
             ok++;


     }
     if (ok==cerinte.size())
         return "OK";
     return "NOK";
 }

int main() {
    int n, minlength, maxlength,nrcond,maxrep,maxcount;
    string conditie,parola;
    char caracter;
    cin >> n;
    vector<Policy *> cerinte;

    for (int i = 0; i < n; ++i)
    {
        cin >> conditie;
        if (conditie == "length")
        {
            cin >> minlength;
                if(islower( cin.peek()))
                {

                    cerinte.push_back(new LengthPolicy(minlength, maxlength));
                }
                else
             cerinte.push_back(new LengthPolicy(minlength));
        }

        if (conditie == "class") {
            cin >> nrcond;
            cerinte.push_back(new ClassPolicy(nrcond));
        }
        if (conditie == "include") {
            cin >> caracter;
            cerinte.push_back(new IncludePolicy(caracter));
        }
        if (conditie == "ninclude") {
            cin >> caracter;
            cerinte.push_back(new NotIncludePolicy(caracter));
        }
        if (conditie == "repetition") {
            cin >> maxrep;
            cerinte.push_back(new RepetitionPolicy(maxrep));
        }
        if (conditie == "consecutive") {
            cin >> maxcount;
            cerinte.push_back(new ConsecutivePolicy(maxcount));
        }
    }

    while (cin>>parola) {

       cout<<checkPassword(parola, cerinte)<<endl;
       cout<<"asta s-a modificat"
    }

    return 0;
}
