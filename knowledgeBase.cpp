#include <iostream>
using namespace std;

class knowledgeBase
{
public:
    //Variables declaration
    static const int size = 41;//variable count
    static const int clauseSize = 81;//clause size
    string conclt[size], varlt[size], clvarlt[clauseSize];
    string varble, Sea_saw_mood_swing, Extreme_depression, NeuroTransmitter, Social_isolation, Hypermania, Lack_of_emotion, Delution, Hypomania, habits, Sleep_diorder, chonic_symptomatic_disorder, Chronic_depression;
    string Fear_open, Fear_closed, Panic_attack, Insomnia, leaving_home, Stress, Susidal_thoughts, Amnesia, Anxiety, paranoid, Loss_Of_Control, UnwantedThoughts, RapidHeartRate, Numb, Guilty, disintrest_life, Fatigue, ExcessiveSweating;
    string Extreme_stress, fear_of_not_being_good_enough, deepsadness, slowmoment, Thoughtdisorder, actingsick, fainting, difficultyinsleeping, possesiveness_protectiveness, norejection;
    string disease = "";
    char buff[256];
    int instlt[size];
    int statsk[size], clausk[size], sn, f, i, j, s, k, sp;

    //Methods
    void initialization();
    void initkbase();
    void ifkbase();
    void thenkbase();
};

void knowledgeBase::initialization()
{
    // Starting with stack space at 10+1
    sp = size;
    for (i = 1; i < size; i++)
    {
        conclt[i] = "";
        varlt[i] = "";
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
    }
    for (i = 1; i < clauseSize + 1; i++)
        clvarlt[i] = "";

    // changing all the conclusion list to DISORD
    for (int i = 1; i < 21; i++)
    {
        conclt[i] = "DISEASE";
    }

    // Printing Conclusion list
    cout << "*** CONCLUSION LIST ***" << endl;
    for (i = 1; i < size; i++)
    {
        if (conclt[i] != "")
            cout << "CONCLUSION " << i << " " << conclt[i] << endl;
    }
    cout << "HIT ENTER OR RETURN TO CONTINUE";
    gets(buff);

    // variable list in the VARLT array

    varlt[1] = "Sea_saw_mood_swing";
    varlt[2] = "Extreme_depression";
    varlt[3] = "Social_isolation";
    varlt[4] = "NeuroTransmitter";
    varlt[5] = "Lack_of_emotion";
    varlt[6] = "Hypermania";
    varlt[7] = "Delution";
    varlt[8] = "Hypomania";
    varlt[9] = "habits";
    varlt[10] = "Sleep_diorder";
    varlt[11] = "chonic_symptomatic_disorder";
    varlt[12] = "Chronic_depression";
    varlt[13] = "Fear_open";
    varlt[14] = "Fear_closed";
    varlt[15] = "Panic_attack";
    varlt[16] = "Insomnia";
    varlt[17] = "leaving_home";
    varlt[18] = "Stress";
    varlt[19] = "Susidal_thoughts";
    varlt[20] = "Amnesia";
    varlt[21] = "Anxiety";
    varlt[22] = "paranoid";
    varlt[23] = "Loss_Of_Control";
    varlt[24] = "UnwantedThoughts";
    varlt[25] = "RapidHeartRate";
    varlt[26] = "Numb";
    varlt[27] = "Guilty";
    varlt[28] = "disintrest_life";
    varlt[29] = "Fatigue";
    varlt[30] = "ExcessiveSweating";
    varlt[31] = "Extreme_stress";
    varlt[32] = "fear_of_not_being_good_enough";
    varlt[33] = "deepsadness";
    varlt[34] = "slowmoment";
    varlt[35] = "Thoughtdisorder";
    varlt[36] = "actingsick";
    varlt[37] = "fainting";
    varlt[38] = "difficultyinsleeping";
    varlt[39] = "possesiveness_protectiveness";
    varlt[40] = "norejection";



    // Printing Variable List
    cout << "*** VARIABLE LIST ***" << endl;
    for (i = 1; i < size; i++)
        cout << "VARIABLE " << i << " " << varlt[i] << endl;

    cout << "HIT RETURN TO CONTINUE";
    gets(buff);

    // clause variable list in clvarlt
    clvarlt[1] = "Sea_saw_mood_swing";
    clvarlt[2] = "Extreme_depression";
    clvarlt[3] = "Social_isolation";
    clvarlt[4] = "";

    clvarlt[5] = "NeuroTransmitter";
    clvarlt[6] = "Lack_of_emotion";
    clvarlt[7] = "Hypermania";
    clvarlt[8] = "";

    clvarlt[9] = "Delution";
    clvarlt[10] = "Hypomania";
    clvarlt[11] = "habits";
    clvarlt[12] = "";

    clvarlt[13] = "Sleep_diorder";
    clvarlt[14] = "chonic_symptomatic_disorder";
    clvarlt[15] = "Chronic_depression";
    clvarlt[16] = "";

    clvarlt[17] = "Fear_open";
    clvarlt[18] = "Fear_closed";
    clvarlt[19] = "Panic_attack";
    clvarlt[20] = "";

    clvarlt[21] = "Fear_open";
    clvarlt[22] = "Insomnia";
    clvarlt[23] = "leaving_home";
    clvarlt[24] = "";

    clvarlt[25] = "Stress";
    clvarlt[26] = "Susidal_thoughts";
    clvarlt[27] = "Amnesia";
    clvarlt[28] = "";

    clvarlt[29] = "Anxiety";
    clvarlt[30] = "paranoid";
    clvarlt[31] = "Loss_Of_Control";
    clvarlt[32] = "";

    clvarlt[33] = "UnwantedThoughts";
    clvarlt[34] = "RapidHeartRate";
    clvarlt[35] = "Numb";
    clvarlt[36] = "";

    clvarlt[37] = "Guilty";
    clvarlt[38] = "disintrest_life";
    clvarlt[39] = "";
    clvarlt[40] = "";

    clvarlt[41] = "Fatigue";
    clvarlt[42] = "Extreme_stress";
    clvarlt[43] = "";
    clvarlt[44] = "";

    clvarlt[45] = "fear_of_not_being_good_enough";
    clvarlt[46] = "";
    clvarlt[47] = "";
    clvarlt[48] = "";

    clvarlt[49] = "deepsadness";
    clvarlt[50] = "slowmoment";
    clvarlt[51] = "";
    clvarlt[52] = "";

    clvarlt[53] = "deepsadness";
    clvarlt[54] = "slowmoment";
    clvarlt[55] = "";
    clvarlt[56] = "";

    clvarlt[57] = "Thoughtdisorder";
    clvarlt[58] = "";
    clvarlt[59] = "";
    clvarlt[60] = "";

    clvarlt[61] = "Thoughtdisorder";
    clvarlt[62] = "actingsick";
    clvarlt[63] = "";
    clvarlt[64] = "";

    clvarlt[65] = "Thoughtdisorder";
    clvarlt[66] = "actingsick";
    clvarlt[67] = "";
    clvarlt[68] = "";

    clvarlt[69] = "fainting";
    clvarlt[70] = "";
    clvarlt[71] = "";
    clvarlt[72] = "";

    clvarlt[73] = "difficultyinsleeping";
    clvarlt[74] = "";
    clvarlt[75] = "";
    clvarlt[76] = "";

    clvarlt[77] = "possesiveness_protectiveness";
    clvarlt[78] = "norejection";
    clvarlt[79] = "";
    clvarlt[80] = "";




    //Printing Clause Variable List
    cout << "*** CLAUSE VARIABLE LIST ***" << endl;
    for (i = 1; i <= clauseSize / 4; i++)
    {
        cout << "** CLAUSE " << i << " **" << endl;
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            cout << "VARIABLE " << j << " " << clvarlt[k] << endl;
        }
        if (i == 4)
        {
            cout << "HIT RETURN TO CONTINUE";
            gets(buff);
        }
    }
}

void knowledgeBase::ifkbase()
{
    switch (sn)
    {
        /* if part of statement 1 */
        /****** comment 1500 ****/
    case 1:
        if (Sea_saw_mood_swing == "YES" && Extreme_depression == "YES" && Social_isolation == "YES")
            s = 1;
        break;
    case 2:
        if (NeuroTransmitter == "YES" && Lack_of_emotion == "YES" && Hypermania == "YES")
            s = 1;
        break;
    case 3:
        if (Delution == "YES" && Hypomania == "YES" && habits == "YES")
            s = 1;
        break;
    case 4:
        if (Sleep_diorder == "YES" && chonic_symptomatic_disorder == "YES" && Chronic_depression == "YES")
            s = 1;
        break;
    case 5:
        if (Fear_open == "YES" && Fear_closed == "YES" && Panic_attack == "YES")
            s = 1;
        break;
    case 6:
        if (Fear_open == "NO" && Insomnia == "YES" && leaving_home == "YES")
            s = 1;
        break;
    case 7:
        if (Stress == "YES" && Susidal_thoughts == "YES" && Amnesia == "YES")
            s = 1;
        break;
    case 8:
        if (Anxiety == "YES" && paranoid == "YES" && Loss_Of_Control == "YES")
            s = 1;
        break;
    case 9:
        if (UnwantedThoughts == "YES" && RapidHeartRate == "YES" && Numb == "YES")
            s = 1;
        break;
    case 10:
        if (Guilty == "YES" && disintrest_life == "YES")
            s = 1;
        break;
    case 11:
        if (Fatigue == "YES" && Extreme_stress == "YES")
            s = 1;
        break;
    case 12:
        if (fear_of_not_being_good_enough == "YES")
            s = 1;
        break;
    case 13:
        if (deepsadness == "YES" && slowmoment == "YES")
            s = 1;
        break;
    case 14:
        if (deepsadness == "YES" && slowmoment == "NO")
            s = 1;
        break;
    case 15:
        if (Thoughtdisorder == "YES")
            s = 1;
        break;
    case 16:
        if (Thoughtdisorder == "YES" && actingsick == "YES")
            s = 1;
        break;
    case 17:
        if (Thoughtdisorder == "YES" && actingsick == "NO")
            s = 1;
        break;
    case 18:
        if (fainting == "YES")
            s = 1;
        break;
    case 19:
        if (difficultyinsleeping == "YES")
            s = 1;
        break;
    case 20:
        if (possesiveness_protectiveness == "YES" && norejection == "NO")
            s = 1;
        break;

    }
}

void knowledgeBase::initkbase()
{
    switch (i)
    {
        /* input statements for sample position knowledgeBase base */
    case 1:
        cout << "Do You Have Sea Saw Mood Swings? (Type YES or NO) ";
        cin >> Sea_saw_mood_swing;
        break;
    case 2:
        cout << "Do You Have Extreme_depression?(Type YES or NO)  ";
        cin >> Extreme_depression;
        break;
    case 3:
        cout << "Are You Socially Isolated?(Type YES or NO)  ";
        cin >> Social_isolation;
        break;
    case 4:
        cout << "Do You Imbalance in Neuro Transmitter?(Type YES or NO) ";
        cin >> NeuroTransmitter;
        break;
    case 5:
        cout << "Do You Lack Emotion?(Type YES or NO)  ";
        cin >> Lack_of_emotion;
        break;
    case 6:
        cout << "Do You Have Hypermania? (Type YES or NO) ";
        cin >> Hypermania;
        break;
    case 7:
        cout << "Are you Delutional?(Type YES or NO)  ";
        cin >> Delution;
        break;
    case 8:
        cout << "Do You Have Hypomania?(Type YES or NO)  ";
        cin >> Hypomania;
        break;
    case 9:
        cout << "Do You HAve Bad Habits which Cause Halucination and Dis Organised Thinking? (Type YES or NO) ";
        cin >> habits;
        break;
    case 10:
        cout << "Do You Have Sleep Disorder?(Type YES or NO)  ";
        cin >> Sleep_diorder;
        break;
    case 11:
        cout << "Do You Have chonic symptomatic disorder? (Type YES or NO) ";
        cin >> chonic_symptomatic_disorder;
        break;
    case 12:
        cout << "Rapid HeartRate?(Type YES or NO)  ";
        cin >> Chronic_depression;
        break;
    case 13:
        cout << "Are You Afraid Of Open Space? (Type YES or NO) ";
        cin >> Fear_open;
        break;
    case 14:
        cout << "Do You Get Afraid Of Enclosed Space?(Type YES or NO)  ";
        cin >> Fear_closed;
        break;
    case 15:
        cout << "Do You Get Panic Attack?(Type YES or NO)  ";
        cin >> Panic_attack;
        break;
    case 16:
        cout << "Do YOu Have Insomnia?(Type YES or NO)  ";
        cin >> Insomnia;
        break;
    case 17:
        cout << "Can You Leave Home Alone?(Type YES or NO)  ";
        cin >> leaving_home;
        break;
    case 18:
        cout << "Do You Have Stress? (Type YES or NO) ";
        cin >> Stress;
        break;
    case 19:
        cout << "Do You Have Thoughts Of Suicide?(Type YES or NO)  ";
        cin >> Susidal_thoughts;
        break;
    case 20:
        cout << "Do You Have Amnesia?(Type YES or NO)  ";
        cin >> Amnesia;
        break;
    case 21:
        cout << "Do You Have Anxiety?(Type YES or NO)  ";
        cin >> Anxiety;
        break;
    case 22:
        cout << "Do You Get Paranoid? (Type YES or NO) ";
        cin >> paranoid;
        break;
    case 23:
        cout << "Do You Loose Control Of Your Body?(Type YES or NO)  ";
        cin >> Loss_Of_Control;
        break;
    case 24:
        cout << "Do You Have Unwanted Thoughts? (Type YES or NO) ";
        cin >> UnwantedThoughts;
        break;
    case 25:
        cout << "Do You Have Rapid Heart Rate?(Type YES or NO)  ";
        cin >> RapidHeartRate;
        break;
    case 26:
        cout << "Do You Feel Numb?(Type YES or NO)  ";
        cin >> Numb;
        break;
    case 27:
        cout << "Do You Feel Guilty About Your Previous Actions?(Type YES or NO)  ";
        cin >> Guilty;
        break;
    case 28:
        cout << "Are You Disintrested In Life? (Type YES or NO) ";
        cin >> disintrest_life;
        break;
    case 29:
        cout << "Do You Feel Fatigue?(Type YES or NO)  ";
        cin >> Fatigue;
        break;
    case 30:
        cout << "Do You Sweat Excessively?(Type YES or NO)  ";
        cin >> ExcessiveSweating;
        break;
    case 31:
        cout << "Are You Extremly Stressed?(Type YES or NO)  ";
        cin >> Extreme_stress;
        break;
    case 32:
        cout << "Are You Afraid Of Not Being Good Enough?(Type YES or NO)  ";
        cin >> fear_of_not_being_good_enough;
        break;
    case 33:
        cout << "Are You Lathergic?(Type YES or NO)  ";
        cin >> slowmoment;
        break;
    case 34:
        cout << "Are You Extremly Sad? (Type YES or NO) ";
        cin >> deepsadness;
        break;
    case 35:
        cout << "Do You Have Disoreantation In Thoughts?(Type YES or NO)  ";
        cin >> Thoughtdisorder;
        break;
    case 36:
        cout << "Are You Acting Sick?(Type YES or NO)  ";
        cin >> actingsick;
        break;
    case 37:
        cout << "Do You Normaly Faint? (Type YES or NO) ";
        cin >> fainting;
        break;
    case 38:
        cout << "Do You Have Difficulty In Sleeping?(Type YES or NO)  ";
        cin >> difficultyinsleeping;
        break;
    case 39:
        cout << "Are You possesive and protective of someone ?(Type YES or NO)  ";
        cin >> possesiveness_protectiveness;
        break;
    case 40:
        cout << "Can You Accept Rejection?(Type YES or NO)  ";
        cin >> norejection;
        break;


    }
}

void knowledgeBase::thenkbase()
{
    switch (sn)
    {




    case 1:
        disease = "BIPOLAR_DISORDER";
        cout << endl << " DISEASE = BIPOLAR DISORDER " << endl;
        break;
    case 2:
        disease = "SCHIZOPHERNIA";
        cout << endl << " DISEASE = SCHIZOPHERNIA " << endl;
        break;
    case 3:
        disease = "SCHIZO_AFFECTIVE_DISORDER";
        cout << endl << " DISEASE = SCHIZO AFFECTIVE DISORDER " << endl;
        break;
    case 4:
        disease = "MAJOR_DEPRESSIVE_DISODER";
        cout << endl << " DISEASE = PANIC DISORDER " << endl;
        break;
    case 5:
        disease = "AGORAPHOBIA";
        cout << endl << " DISEASE = MAJOR DEPRESSIVE DISODER " << endl;
        break;
    case 6:
        disease = "PANIC_DISORDER_WITH_AGORAPHOBIA";
        cout << endl << " DISEASE = AGORAPHOBIA " << endl;
        break;
    case 7:
        disease = "DISASSOCIATIVE_IDENTITY";
        cout << endl << " DISEASE = DISASSOCIATIVE IDENTITY " << endl;
        break;

    case 8:
        disease = "ANXIETY";
        cout << endl << " DISEASE = ANXIETY " << endl;
        break;
    case 9:
        disease = "EMOTIONAL_DISTRESS";
        cout << endl << " DISEASE = EMOTIONAL DISTRESS " << endl;
        break;
    case 10:
        disease = "DYSTHYMIA";
        cout << endl << " DISEASE = DYSTHYMIA " << endl;
        break;
    case 11:
        disease = "ACUTE_STRESS_DISORDER";
        cout << endl << " DISEASE = ACUTE STRESS DISORDER " << endl;
        break;
    case 12:
        disease = "ATHELOPHOBIA";
        cout << endl << " DISEASE = ATHELOPHOBIA " << endl;
        break;
    case 13:
        disease = "CATANOIA";
        cout << endl << " DISEASE = CATANOIA " << endl;
        break;
    case 14:
        disease = "DEPRESSION";
        cout << endl << " DISEASE = DEPRESSION " << endl;
        break;
    case 15:
        disease = "DELUSIONAL_DISORDER";
        cout << endl << " DISEASE = DELUSIONAL DISORDER " << endl;
        break;
    case 16:
        disease = "FACTIOUS_DISORDER";
        cout << endl << " DISEASE = FACTIOUS DISORDER " << endl;
        break;
    case 17:
        disease = "GANSER_SYNDROME";
        cout << endl << " DISEASE = GANSER SYNDROME " << endl;
        break;
    case 18:
        disease = "EPILEPSY";
        cout << endl << " DISEASE = EPILEPSY " << endl;
        break;
    case 19:
        disease = "INSOMNIA";
        cout << endl << " DISEASE = INSOMNIA " << endl;
        break;
    case 20:
        disease = "OBSESSIVE_LOVE";
        cout << endl << " DISEASE = OBSESSIVE LOVE " << endl;
        break;



    }
}