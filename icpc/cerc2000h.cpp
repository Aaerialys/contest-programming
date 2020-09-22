#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=(int)a;i<(int)b;i++)
#define forj(a,b) for(int j=(int)a;j<(int)b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=150,NN=1000;

struct Fact
{
	bool pos;
	string s,v,o;
};
int contra,cur;
string sentence;
string temp;
vector<Fact> facts;

string word()
{
    if(cur>0)
        cur++;
    if(cur>sentence.size())
        return "";
    fori(cur,sentence.size()+1)
    {
        if(i==sentence.size()||sentence[i]==' ')
        {
            swap(i,cur);
            return sentence.substr(i,cur-i);
        }
    }
    return "";
}
string conj(string verb, string subject)
{
	if(subject!="I"&&subject!="you")
		verb+='s';
    return verb;
}
string infin(string verb,string subject)
{
	if(subject!="I"&&subject!="you")
        verb=verb.substr(0,verb.size()-1);
    return verb;
}
string persRev(string subject)
{
    if(subject == "I")
        return "you";
    if(subject == "you")
        return "I";
    return subject;
}
void doesWho(string subject, string verb, string object)
{
	fori(0,facts.size())
	{
		if(facts[i].v!=verb||facts[i].o!=object)
            continue;
		if(facts[i].s!="everybody"&&facts[i].s!=subject)
            continue;
        subject=persRev(subject);
		if(facts[i].pos)
			cout<<"yes, "<<subject<<" "<<conj(verb,subject)<<(object!=""? " ": "")<<object<<".\n";
		else
            cout<<"no, "<<subject<<" "<<((subject=="I"||subject=="you")? "don't": "doesn't")<<" "<<verb<<(object!=""? " ": "")<<object<<".\n";
		return;
	}
	cout<<"maybe.\n";
}
void whoDo(string verb,string object)
{
    vector<string> ans;
	fori(0,facts.size())
		if(facts[i].v==verb&&facts[i].o==object)
		{
		    if(facts[i].s=="everybody")
            {
                if(facts[i].pos)
                    cout<<"everybody "<<conj(verb,"everybody")<<(object!=""? " ": "")<<object<<".\n";
                else
                    cout<<"nobody "<<conj(verb,"nobody")<<(object!=""? " ": "")<<object<<".\n";
                return;
            }
			if(facts[i].pos)
			    ans.push_back(persRev(facts[i].s));
		}
	if(!ans.size())
	{
        cout<<"I don't know.\n";
		return;
	}
	fori(0,ans.size())
	{
        if(i>0&&i==ans.size()-1)
            cout<<" and ";//nocomma
        else if(i>0)
            cout<<", ";
        cout<<ans[i];
	}
	if(ans.size()==1)
        verb=conj(verb,ans[0]);
    else
        verb=conj(verb,"I");
	cout<<" "<<verb<<(object!=""? " ": "")<<object<<".\n";
}
void doWho(string subject)
{
    vector<Fact> ans;
	fori(0,facts.size())
		if(facts[i].s==subject.c_str()||facts[i].s=="everybody")
			ans.push_back(facts[i]);
	if(!ans.size())
	{
        cout<<"I don't know.\n";
		return;
	}
	cout<<persRev(subject)<<" ";
	fori(0,ans.size())
	{
        if(i>0&&i==(int)ans.size()-1)
            cout<<", and ";
        else if(i>0)
            cout<<", ";
		if(ans[i].pos)
			cout<<conj(ans[i].v,subject)<<(ans[i].o!=""? " ": "")<<ans[i].o;
		else
			cout<<((subject=="I"||subject=="you")? "don't": "doesn't")<<" "<<ans[i].v<<(ans[i].o!=""? " ": "")<<ans[i].o;
	}
	cout<<".\n";
}
void ask()
{
	string verb,subject,object;
	temp=word();
	if(contra)
	{
		cout<<"I am abroad.\n";
		return;
	}
	if(temp=="do"||temp=="does")
	{
		subject=word();
		verb=word();
        if(cur<(int)sentence.size())
            object=sentence.substr(cur+1);
		doesWho(subject,verb,object);
	}
	else if(temp=="who")
	{
		verb=infin(word(),"who");
        if(cur<sentence.size())
            object=sentence.substr(cur+1);
		whoDo(verb,object);
		return;
	}
	else
	{
		word();
		subject=word();
		doWho(subject);
	}
}
void newFact()
{
	string subject,verb,object;
	bool positive=true;
	if(contra)
        return;
	subject=word(); verb=word();
	if(verb=="don't"||verb=="doesn't")
	{
		positive=false;
        verb=word();
	}
	else
		verb=infin(verb,subject);
	if(subject=="nobody")
	{
		positive=!positive;
		subject="everybody";
	}
	if(cur<(int)sentence.size())
        object=sentence.substr(cur+1);
	fori(0,facts.size())
	{
		if(facts[i].v!=verb||facts[i].o!=object)
            continue;
        if(facts[i].s=="everybody"||subject==facts[i].s)
        {
            if(positive!=facts[i].pos)
                contra=true;
            return;
        }
		if(subject=="everybody")
		{
			if(facts[i].pos!=positive)
			{
				contra=true;
				return;
			}
			facts.erase(facts.begin()+i);
			i--;
		}
	}
	facts.push_back({positive,subject,verb,object});
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("output.txt", "w", stdout);
	int n;
	cin>>n; cin.ignore();
	fori(0,n)
	{
		cout<<"Dialogue #"<<i+1<<":\n";
		facts.clear();
        contra=false;
        while(true)
        {
            cur=0;
            getline(cin,sentence);
            if(sentence[sentence.size()-1]=='?')
            {
                cout<<sentence<<"\n";
                sentence=sentence.substr(0,sentence.size()-1);
                ask();
                cout<<"\n";
            }
            else if(sentence[sentence.size()-1]== '.')
            {
                sentence=sentence.substr(0,sentence.size()-1);
                newFact();
            }
            else if(sentence[sentence.size()-1]=='!')
            {
                cout<<sentence<<"\n";
                break;
            }
        }
        cout<<"\n";/*
        cout<<"\n\n\n";
        fori(0,snum)
            cout<<facts[i].s<<" "<<facts[i].v<<" "<<facts[i].o<<" "<<facts[i].pos<<endl;
        cout<<"\n\n\n";*/
	}
    return 0;
}