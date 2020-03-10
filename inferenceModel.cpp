#include <iostream>
using namespace std;
#include "knowledgeModel.cpp"

class inferenceModel
{
    //Methods incorporated in Inference Model Class
public:
    knowledgeModel knowledgemodelInstance;
    void searchInference();
    void check_instantiationInference();
    void instantiateInference();
    void inference(string);
    void processInference();
    void startInference(string);
    void displayInference();
};


//DisplayInference
void inferenceModel::displayInference()
{
    cout << "Printing The Conclusion Variable Queue";
    bool flag = true;
    for (int i1 = 1; i1 < 2; i1++)
    {
        if (knowledgemodelInstance.cnVariable[i1] != "")
        {
            cout << "| " << knowledgemodelInstance.cnVariable[i1] << " |";
            flag = false;
            cout << endl;
        }
    }
    if (flag)
    {
        cout << "There are no elements in Conclusion Variable Queue" << endl;
    }
    else
    {
        cout << endl;
    }
}

//Start Inference
void inferenceModel::startInference(string t)
{
    knowledgemodelInstance.startkbase();
    inference(t);
    processInference();
}

//To Check The Instantiation
void inferenceModel::check_instantiationInference()
{
    knowledgemodelInstance.i = 1;
    while ((knowledgemodelInstance.v != knowledgemodelInstance.variableList[knowledgemodelInstance.i]) && (knowledgemodelInstance.i < knowledgemodelInstance.size))
        knowledgemodelInstance.i = knowledgemodelInstance.i + 1;
    if (knowledgemodelInstance.instantiateList[knowledgemodelInstance.i] != 1)
    {
        knowledgemodelInstance.instantiateList[knowledgemodelInstance.i] = 1;
        knowledgemodelInstance.instantiatekbase();
    }
}

//To Instantiate Inference
void inferenceModel::instantiateInference()
{
    knowledgemodelInstance.i = 1;
    while ((knowledgemodelInstance.v != knowledgemodelInstance.variableList[knowledgemodelInstance.i]) && (knowledgemodelInstance.i < knowledgemodelInstance.size))
        knowledgemodelInstance.i = knowledgemodelInstance.i + 1;
    knowledgemodelInstance.instantiateList[knowledgemodelInstance.i] = 1;
    knowledgemodelInstance.i = 1;
    while ((knowledgemodelInstance.v != knowledgemodelInstance.cnVariable[knowledgemodelInstance.i]) && (knowledgemodelInstance.i < knowledgemodelInstance.size))
        knowledgemodelInstance.i = knowledgemodelInstance.i + 1;
    if (knowledgemodelInstance.v != knowledgemodelInstance.cnVariable[knowledgemodelInstance.i])
    {
        knowledgemodelInstance.cnVariable[knowledgemodelInstance.bp] = knowledgemodelInstance.v;
        knowledgemodelInstance.bp = knowledgemodelInstance.bp + 1;
    }
}

//To Call Inference Model Method
void inferenceModel::inference(string forward)
{
    cout << endl;
    knowledgemodelInstance.fp = 1;
    knowledgemodelInstance.bp = 1;
    knowledgemodelInstance.c = "DISORD";
    knowledgemodelInstance.disease = forward;
    knowledgemodelInstance.instantiateList[1] = 1;
    knowledgemodelInstance.cnVariable[knowledgemodelInstance.bp] = knowledgemodelInstance.c;
    knowledgemodelInstance.bp = knowledgemodelInstance.bp + 1;
    knowledgemodelInstance.sn = 1;
    knowledgemodelInstance.cn = 1;
    /* start at the beginning */
    knowledgemodelInstance.f = 1;
}

// To Process Inference and Run Index
void inferenceModel::processInference()
{
    searchInference();
    knowledgemodelInstance.cn = 1;
    if (knowledgemodelInstance.sn != 0)
    {

        knowledgemodelInstance.i = 4 * (knowledgemodelInstance.sn - 1) + knowledgemodelInstance.cn;
        knowledgemodelInstance.v = knowledgemodelInstance.clvariableList[knowledgemodelInstance.i];

        while (knowledgemodelInstance.v != "")

        {

            check_instantiationInference();
            knowledgemodelInstance.cn = knowledgemodelInstance.cn + 1;

            knowledgemodelInstance.i = 4 * (knowledgemodelInstance.sn - 1) + knowledgemodelInstance.cn;
            knowledgemodelInstance.v = knowledgemodelInstance.clvariableList[knowledgemodelInstance.i];
        }


        knowledgemodelInstance.s = 0;

        knowledgemodelInstance.ifkbase();


        if (knowledgemodelInstance.s != 1)
        {
            knowledgemodelInstance.f = knowledgemodelInstance.sn + 1;
            processInference();
        }

        knowledgemodelInstance.thenkbase();
        if (knowledgemodelInstance.inst)
        {
            instantiateInference();
            knowledgemodelInstance.inst = false;
        }
        knowledgemodelInstance.f = knowledgemodelInstance.sn + 1;
        processInference();
    }

    knowledgemodelInstance.fp = knowledgemodelInstance.fp + 1;
    if (knowledgemodelInstance.fp < knowledgemodelInstance.bp)
    {

        knowledgemodelInstance.f = 1;
        processInference();
    }

    cout << "End of Intelligence's Result" << endl;
    exit(0);
}

//To Search onInference
void inferenceModel::searchInference()
{
    knowledgemodelInstance.flag = 0;
    knowledgemodelInstance.sn = knowledgemodelInstance.f;
    while ((knowledgemodelInstance.flag == 0) && (knowledgemodelInstance.sn <= (knowledgemodelInstance.csize - 1) / 4))
    {
        knowledgemodelInstance.cn = 1;
        knowledgemodelInstance.k = (knowledgemodelInstance.sn - 1) * 4 + knowledgemodelInstance.cn;
        while ((knowledgemodelInstance.clvariableList[knowledgemodelInstance.k] != knowledgemodelInstance.cnVariable[knowledgemodelInstance.fp]) && (knowledgemodelInstance.cn < 4))
        {
            knowledgemodelInstance.cn = knowledgemodelInstance.cn + 1;
            knowledgemodelInstance.k = (knowledgemodelInstance.sn - 1) * 4 + knowledgemodelInstance.cn;
        }

        if (knowledgemodelInstance.clvariableList[knowledgemodelInstance.k] == knowledgemodelInstance.cnVariable[knowledgemodelInstance.fp])
            knowledgemodelInstance.flag = 1;
        if (knowledgemodelInstance.flag == 0)
            knowledgemodelInstance.sn = knowledgemodelInstance.sn + 1;
    }
    if (knowledgemodelInstance.flag == 0)
        knowledgemodelInstance.sn = 0;
}
