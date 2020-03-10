//inferenceEngine.cpp
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class knowledgeModel
{
public:
    string disease, treatment;
    int flag;
    bool inst = false;
    static const int size = 2; //variable list size
    static const int csize = 81; // clause variable list size
    string cnVariable[size], variableList[size], clvariableList[csize];
    string c, v;
    int instantiateList[size];

    /* front pointer */
    int i, j, k, f, s, fp;

    /* back pointer */
    int  bp;

    /* statement number */
    int sn;

    /* clause number */
    int cn;

    char bufferBox[500];
    //Methods
    void inline startkbase();
    void inline ifkbase();
    void inline thenkbase();
    void inline instantiatekbase();
};

void knowledgeModel::startkbase()
{
    /******** INITIALIZATION SECTION ***********/
    for (i = 1; i < csize; i++)
        clvariableList[i] = "";
    for (i = 1; i < size; i++)
    {
        cnVariable[i] = "";
        variableList[i] = "";
        instantiateList[i] = 0;
    }
    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */


    variableList[1] = "DISORD";

    cout << "*** VARIABLE LIST ***" << endl;
    for (i = 1; i < size; i++)
    {
        cout << "VARIABLE " << i << " " << variableList[i] << endl;
    }
    cout << endl;

    cout << "HIT ENTER OR RETURN TO CONTINUE";
    gets(bufferBox);


    //Initializing clause variable list
    for (int i = 1; i < csize; i += 4)
    {
        clvariableList[i] = "DISORD";
    }


    printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i <= (csize - 1) / 4; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            cout << "VARIABLE " << j << " " << clvariableList[k] << endl;
        }

        if (i == 10)
        {
            cout << "HIT RETURN TO CONTINUE";
            gets(bufferBox);
        }
    }
    cout << endl;
}

void knowledgeModel::ifkbase()
{
    /* statements for if-then from knowledge base */
    switch (sn)
    {
   
    case 1:
        if (disease == "BIPOLAR_DISORDER")
            s = 1;
        break;
     
    case 2:
        if (disease == "SCHIZOPHERNIA")
            s = 1;
        break;
   
    case 3:
        if (disease == "SCHIZO_AFFECTIVE_DISORDER")
            s = 1;
        break;
     
    case 4:
        if (disease == "PANIC_DISORDER")
            s = 1;
        break;
      
    case 5:
        if (disease == "MAJOR_DEPRESSIVE_DISODER")
            s = 1;
        break;
      
    case 6:
        if (disease == "AGORAPHOBIA")
            s = 1;
        break;
    case 7:
        if (disease == "DISASSOCIATIVE_IDENTITY")
            s = 1;
        break;
    case 8:
        if (disease == "ANXIETY")
            s = 1;
        break;
    case 9:
        if (disease == "EMOTIONAL_DISTRESS")
            s = 1;
        break;
    case 10:
        if (disease == "DYSTHYMIA")
            s = 1;
        break;
    case 11:
        if (disease == "ACUTE_STRESS_DISORDER")
            s = 1;
        break;
    case 12:
        if (disease == "ATHELOPHOBIA")
            s = 1;
        break;
    case 13:
        if (disease == "CATANOIA")
            s = 1;
        break;
    case 14:
        if (disease == "DELUSIONAL_DISORDER")
            s = 1;
        break;
    case 15:
        if (disease == "DEPRESSION")
            s = 1;
        break;
    case 16:
        if (disease == "EPILEPSY")
            s = 1;
        break;
    case 17:
        if (disease == "FACTIOUS_DISORDER")
            s = 1;
        break;
    case 18:
        if (disease == "GANSER_SYNDROME")
            s = 1;
        break;
    case 19:
        if (disease == "INSOMNIA")
            s = 1;
        break;
    case 20:
        if (disease == "OBSESSIVE_LOVE")
            s = 1;
        break;
      
    }
}

void knowledgeModel::thenkbase()
{
    /* inserts a variable on the conclusion variable queue, this method invokes the then part of the program */
    switch (sn)
    {

         
    case 1:
        treatment = "MEDICATIONS";
        cout << "TREATMENT = Antipsychotic Medications and cognitive therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
      
         
    case 2:
        treatment = "THERAPY";
        cout << "TREATMENT = Antipsychotic Medications and Psychotherapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
   
         
    case 3:
        treatment = "PSYCHOTHERAPY";
        cout << "TREATMENT = Antipsychotic/Mood stabilizing Medications and psychotherapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
 
         
    case 4:
        treatment = "SELECTIVE SEROTININ REUPTAKE INHIBITOR";
        cout << "TREATMENT = Antidepressant Medications and cognitive therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
         
    case 5:
        treatment = "TRICYCLIC ANTI DEPRESSANTS";
        cout << "TREATMENT =Anti Anxiety Medications and cognitive therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;

    case 6:
        treatment = "Psychiatric Hospitalization";
        cout << "TREATMENT =Anti Anxiety Medications and cognitive therapy PLUS. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
     
         
    case 7:
        treatment = "Dual diagnosis treatment.";
        cout << "TREATMENT =Psychotherapies and possibly medications. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
        
         
    case 8:
        treatment = "Inpatient or residential mental health treatment. Hope you recover soon";
        cout << "TREATMENT = Prescription Drugs." << endl;
        v = "DISORD";
        inst = true;
        break;
       
         
    case 9:
        treatment = "12-step programs and support groups.";
        cout << "TREATMENT = Counselling and Interpersonal Therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
       
    case 10:
        treatment = "Recovery Program";
        cout << "TREATMENT = Antidepressant Medications and Psychotherapy 3 Weeks. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
    case 11:
        treatment = "Mood-stabilizing medications";
        cout << "TREATMENT = Mood-stabilizing medications and Social Skills Therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
  
         
    case 12:
        treatment = "Nurse practitioner";
        cout << "TREATMENT = Cognitive behavioral therapy. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
        
         
    case 13:
        treatment = "Brain-stimulation treatments";
        cout << "TREATMENT = Benzodiazepines,Tricyclic antidepressants,Muscle relaxants. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
       
         
    case 14:
        treatment = "Substance misuse treatment";
        cout << "TREATMENT = Selective Serotonin Reuptake Inhibitor,Antidepressant,Antipsychotic. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
         
    case 15:
        treatment = "TRICYCLIC ANTI DEPRESSANTS";
        cout << "TREATMENT = Tricyclic Anti Depressants. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;

    case 16:
        treatment = "Psychiatric Hospitalization";
        cout << "TREATMENT = Psychiatric Hospitalization. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;

         
    case 17:
        treatment = "Dual diagnosis treatment";
        cout << "TREATMENT = Psychotherapy to manage stress and develop effective coping skills.Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
  
         
    case 18:
        treatment = "Inpatient or residential mental health treatment.";
        cout << "TREATMENT = Mental examination,computer tomography scans (CT) or magnetic resonance imaging. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
  
         
    case 19:
        treatment = "12-step programs and support groups.";
        cout << "TREATMENT = Self-care,Therapies and Medication.Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;
         
    case 20:
        treatment = "Recovery Program";
        cout << "TREATMENT = Antipsychotics,mood stabilizers,anti-anxiety medications. Hope you recover soon" << endl;
        v = "DISORD";
        inst = true;
        break;

    }
}

void knowledgeModel::instantiatekbase()
{
    switch (i)
    {
        //sample position of knowledge base
    case 1:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 2:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 3:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 4:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 5:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 6:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 7:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 8:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 9:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 10:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 11:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 12:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 13:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 14:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 15:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 16:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 17:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 18:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 19:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;
    case 20:
        cout << "WHAT IS THE DISEASES? ";
        cin >> disease;
        break;

    }
}
