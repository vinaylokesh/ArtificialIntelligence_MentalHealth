#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#include "knowledgeBase.cpp"
#include "inferenceModel.cpp"

class inferenceEngine
{
public:
    //an object to access it's methods and variables
    knowledgeBase kb;
    void startInferenceEngine();
    void process();
    void noConclusion();
    void determine_member_concl_list();
    void push_on_stack();
    void instantiate();
    void popStack();
    void mappingClause();
    string findDisease();
    void display();
};

void inferenceEngine::display()
{
    cout << endl << "--------------------------" << endl;
    cout << "Details of Conclusion Stack: The Conclusion Stack is set to DISEASE";
    cout << endl << "--------------------------" << endl;
    bool flag = true;
    for (int i1 = 1; i1 < kb.size; i1++)
    {
        if (kb.statsk[i1] != 0)
        {
            cout << "| " << kb.statsk[i1] << " |";
            cout << " " << kb.clausk[i1] << " |";
            flag = false;
            cout << endl;
        }
    }
    if (flag)
    {
        cout << "Empty Conclusion Stack";
        cout << endl << "--------------------------" << endl;
    }
    else
    {
        cout << endl << "--------------------------" << endl;
    }
}

string inferenceEngine::findDisease()
{
    return kb.disease;
}




void inferenceEngine::startInferenceEngine()
{
    kb.initialization();
    cout << "\nYOUR CONCLUSION MUST BE DISEASE IN ORDER TO TRACK, ENTER KEYWORD DISEASE: ? ";
    cin >> kb.varble;
    cout << "\n\n";
    process();
}



void inferenceEngine::process()
{
    kb.f = 1;
    determine_member_concl_list();
    if (kb.sn != 0)
    {
        noConclusion();
        if (kb.sn != 0)
        {
            cin.ignore();
            kb.thenkbase();
            popStack();
        }
        
    }
}

void inferenceEngine::noConclusion()
{
    do
        /* push statement number (sn) and clause number=1 on
        goal stack which is composed of the statement stack (statsk) and clause stack (clausk) */
    {
        push_on_stack();
        mappingClause();
    } while ((kb.s != 1) && (kb.sn != 0));
   
}

void inferenceEngine::determine_member_concl_list()
{
    
    kb.sn = 0;
  
    kb.i = kb.f;
    while ((kb.varble != kb.conclt[kb.i]) && (kb.i < 20))
        kb.i = kb.i + 1;
    if (kb.varble == kb.conclt[kb.i])
        kb.sn = kb.i;  
}

void inferenceEngine::push_on_stack()
{
    kb.sp = kb.sp - 1;
    kb.statsk[kb.sp] = kb.sn;
    kb.clausk[kb.sp] = 1;
}

void inferenceEngine::instantiate()
{
    kb.i = 1;
   
    while (kb.varble != kb.varlt[kb.i] && kb.i < kb.size)
        kb.i = kb.i + 1;
    if (kb.varble == kb.varlt[kb.i] && kb.instlt[kb.i] != 1)
    { 
        kb.instlt[kb.i] = 1;
        kb.initkbase();
    }
}

void inferenceEngine::mappingClause()
{
    do
    {
      
        kb.i = (kb.statsk[kb.sp] - 1) * 4 + kb.clausk[kb.sp];
       
        kb.varble = kb.clvarlt[kb.i];
        if (kb.varble != "")
        {
            kb.f = 1;
            determine_member_concl_list();
            if (kb.sn != 0)
                process();   
            instantiate();
            kb.clausk[kb.sp] = kb.clausk[kb.sp] + 1;
        }
    } while (kb.varble != "");
    kb.sn = kb.statsk[kb.sp];
    kb.s = 0;
    kb.ifkbase();
    if (kb.s != 1)
    {
        kb.i = kb.statsk[kb.sp];
        kb.varble = kb.conclt[kb.i];
        kb.f = kb.statsk[kb.sp] + 1;
        determine_member_concl_list();
        kb.sp = kb.sp + 1;
    }
}

void inferenceEngine::popStack()
{
 //to pop the stack
    kb.sp = kb.sp + 1;
    if (kb.sp >= kb.size)
    {
 
        return;
    }
    else
    {
      
        kb.clausk[kb.sp] = kb.clausk[kb.sp] + 1;
        mappingClause();
        if ((kb.s != 1) && (kb.sn != 0))
        {
            noConclusion();
        }
        else if (kb.sn != 0)
        {
            kb.thenkbase();
            popStack();
        }
    }
}

int main()
{
    //Assigning Character Buffer
    char bufferbox[5000];
    string userInput;
    //Clear the Terminal Screen
    if (system("CLS")) system("clear");
    cout << "-----------------------------------------------------------------" << endl;
cout << "-----------------------------------------------------------------" << endl;
    cout << "You are currently using Intelligent System for Mental Health Care" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    //AcceptingTheInputFromUser
    cout << "Do you have Mental Disorder?(YES or NO ):";
    cin >> userInput;
    cin.ignore();

    if (userInput == "NO" || userInput == "no")
    {
        cout << "You have been currently logged out" << endl;
        cout << " " << endl;
        cout << "If you think you have Mental Disorder please login to check again" << endl;
        exit(0);
    }

    //Creating an instance for self class
    inferenceEngine engine;
    engine.startInferenceEngine();

    // Calling inference engine to print conclusion list
    string ftracking = engine.findDisease();
    if (ftracking != "")
    {

        cout << "Hit RETURN or ENTER Key to Start Forward Chaining" << endl;
        gets(bufferbox);
        cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
        cout << "Forward Chaining Begins NOW" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;

        inferenceModel iModel;
        iModel.startInference(ftracking);
    }
    return 0;
}
