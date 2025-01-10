#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include <numeric>
#include <cstdlib> 
#include <fstream>
#include <sstream>
#include <ctime>
#include <list>
#include <random>
#include <stdexcept>


using namespace std;
// Define a struct to hold a question and its options

struct Question {

    string question;
    vector<string> options;
    string CorrectAnswer;
    string YES_NO_Answer;
};

//Class to populate questions

class  Questions
{
public:

    //Computing questions using vector.
    std::vector<Question> quizQuestions = Extractquestion("QuestionBank12txt.txt");
    int currentQuestionIndex = 0;
    const int numQuestions = 8;

    //method extract questions and options from text file and return a vector<Question> quizQuestions
    vector<Question> Extractquestion(const string& filename) {

        ifstream file(filename); // Open the file
        if (!file.is_open()) {
            cerr << "Error: Could not open the file." << endl;

        }

        vector<Question> quizQuestions; // Vector to store questions

        string line;
        while (getline(file, line)) { // Read the file line by line
            if (line.empty()) continue; // Skip empty lines

            // Parse the line into question and options
            stringstream ss(line);
            string question, optionsStr, answer, Answer;

            getline(ss, question, '/');
            getline(ss, optionsStr, '/');
            getline(ss, answer, '/');
            getline(ss, Answer, '/');

            // Parse options
            stringstream optionsSS(optionsStr);
            vector<string> options;
            string option;
            while (getline(optionsSS, option, ',')) {
                options.push_back(option);
            }

            // Create a Question struct
            Question q;
            q.question = question;
            q.options = options;
            q.CorrectAnswer = answer;
            q.YES_NO_Answer = Answer;
            quizQuestions.push_back(q);



        }

        file.close(); // Close the file

        return quizQuestions;



    }

    //Randomly select 8 questions from quizQuestions by shuffling the vector and storing the first 8 elements on a new vector<Question> 
    vector<Question> RandomQuestions(vector<Question> quiz) {

        //shuffles the list in this case vector<Question> quizQuestions
        random_device rand;
        mt19937 g(rand());
        shuffle(quiz.begin(), quiz.end(), g);

        vector<Question> quizz;
        for (int i = 0; i < numQuestions && i < quiz.size(); i++) {
            quizz.push_back(quiz[i]);

        }
        return  quizz;
    }

    vector<Question> quizGame = RandomQuestions(quizQuestions);

    /*
    * AssignQuestion Function displays one question and it options
    */
    void AssignQuestion(System::Windows::Forms::Label^ label1,
        System::Windows::Forms::RadioButton^ radio1,
        System::Windows::Forms::RadioButton^ radio2,
        System::Windows::Forms::RadioButton^ radio3,
        System::Windows::Forms::RadioButton^ radio4, System::Windows::Forms::Label^ label3)
    {

     

        if (currentQuestionIndex >= 0 && currentQuestionIndex < quizGame.size()) {
            System::String^ question = gcnew System::String(quizGame[currentQuestionIndex].question.c_str());
            label1->Text = question;

            System::String^ answer = gcnew System::String(quizGame[currentQuestionIndex].CorrectAnswer.c_str());
            label3->Text = answer;
            // Check if the question is true/false type
            if (quizGame[currentQuestionIndex].options.size() == 2) {
                // True/false question
                radio1->Text = gcnew System::String(quizGame[currentQuestionIndex].options[0].c_str());
                radio2->Text = gcnew System::String(quizGame[currentQuestionIndex].options[1].c_str());

                // Hide unnecessary radio buttons
                radio3->Visible = false;
                radio4->Visible = false;

                // Clear any previous selections
                radio1->Checked = false;
                radio2->Checked = false;
            }
            else if (quizGame[currentQuestionIndex].options.size() > 1) {
                // Multiple-choice question
                radio1->Text = gcnew System::String(quizGame[currentQuestionIndex].options[0].c_str());
                radio2->Text = gcnew System::String(quizGame[currentQuestionIndex].options[1].c_str());

                // Set visibility for additional options
                radio3->Visible = quizGame[currentQuestionIndex].options.size() > 2;
                radio4->Visible = quizGame[currentQuestionIndex].options.size() > 3;

                // Set text for additional options
                if (quizGame[currentQuestionIndex].options.size() > 2) {
                    radio3->Text = gcnew System::String(quizGame[currentQuestionIndex].options[2].c_str());
                }
                if (quizGame[currentQuestionIndex].options.size() > 3) {
                    radio4->Text = gcnew System::String(quizGame[currentQuestionIndex].options[3].c_str());
                }

                //// Clear any previous selections
                radio1->Checked = false;
                radio2->Checked = false;
                radio3->Checked = false;
                radio4->Checked = false;
            }
        }
    }




    void NextQuestion(System::Windows::Forms::Label^ label1,
        System::Windows::Forms::RadioButton^ radio1,
        System::Windows::Forms::RadioButton^ radio2,
        System::Windows::Forms::RadioButton^ radio3,
        System::Windows::Forms::RadioButton^ radio4, System::Windows::Forms::Label^ label3) {
        currentQuestionIndex = NavigateQuestions(currentQuestionIndex, quizGame.size());
        AssignQuestion(label1, radio1, radio2, radio3, radio4, label3);
    }
    void PreviousQuestion(System::Windows::Forms::Label^ label1,
        System::Windows::Forms::RadioButton^ radio1,
        System::Windows::Forms::RadioButton^ radio2,
        System::Windows::Forms::RadioButton^ radio3,
        System::Windows::Forms::RadioButton^ radio4, System::Windows::Forms::Label^ label3) {
        currentQuestionIndex = NavigateQuestionsBackward(currentQuestionIndex);
        AssignQuestion(label1, radio1, radio2, radio3, radio4, label3);
    }




    // Function to navigate questions forward
    int NavigateQuestions(int questionNum, int totalQuestions) {
        if (questionNum < quizQuestions.size()) {
            questionNum++;
        }
       
        return questionNum;
    }

    // Function to navigate questions backward
    int NavigateQuestionsBackward(int questionNum) {
        if (questionNum > 0) {
            questionNum--;
        }
       

        return questionNum;
    }



    //Sources: community.thunkable.com (1) forum.freecodecamp.org (2) forum.arduino.cc (3) forum.unity.com (4)
    // generateRandomNumber only once  
    int generateRandomIndex(int size) {
        static std::mt19937 generator(std::random_device{}());
        static std::vector<int> generatedIndices;

        if (generatedIndices.size() == size) {
            generatedIndices.clear();
        }

        std::uniform_int_distribution<int> distribution(0, size - 1);
        int randomIndex = distribution(generator);

        while (std::find(generatedIndices.begin(), generatedIndices.end(), randomIndex) != generatedIndices.end()) {
            randomIndex = distribution(generator);
        }

        generatedIndices.push_back(randomIndex);
        return randomIndex;
    }

    bool checkAnswer(int SelectedOption) {
        System::String^ answer = gcnew System::String(quizGame[currentQuestionIndex].CorrectAnswer.c_str());
        int CorrectAnswer = System::Convert::ToInt32(answer);
        return(SelectedOption == CorrectAnswer);


    }

    bool checkAnswer(System::String^ SelectedOption) {
        System::String^ answer = gcnew System::String(quizGame[currentQuestionIndex].YES_NO_Answer.c_str());

        return (SelectedOption == answer);
    }

    void AssignQuestion(System::Windows::Forms::RichTextBox^ richTextBox) {

        richTextBox->AppendText(gcnew System::String(quizGame[currentQuestionIndex].question.c_str()) + "\n");
        richTextBox->AppendText("Correct Answer: " + gcnew System::String(quizGame[currentQuestionIndex].YES_NO_Answer.c_str()) + "\n\n");

    }

};