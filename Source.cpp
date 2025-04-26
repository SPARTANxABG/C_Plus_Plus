#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>
#include "HashTable.h"

using namespace std;

typedef HashTable<string>::Iterator iterDec;

const int TABLE_SIZE = 19000;

const char* DELIMITERS = " ,.-\':;?()+*/\\%$#!\"@\^&";

void PrintTableStats(HashTable<string>& hashTable);
int SpellCheck(HashTable<string>& hashTable, string word);
string ToLowerCase(string word);

int main()
{
    int result = 0;
    string userInput;
    string currWord;
    clock_t beg;
    clock_t end;
    char response;
    ifstream infile;
    HashTable<string> hashTable(TABLE_SIZE);

    infile.open("INPUT_Dictionary_programmingnotes_freeweq_com.txt");

    if (infile.fail())
    {
        cout << "\n\n**ERROR - The dictionary file could not be found...\n";
        exit(1);
    }

    cerr << "\nLoading dictionary....";
    beg = clock();

    while (infile >> currWord)
    {
        if (!hashTable.Count(currWord))
        {
            hashTable.Insert(currWord);
        }
    }

    infile.close();
    PrintTableStats(hashTable);

    end = clock() - beg;
    cout << "\n\nDictionary loaded in " <<
        (double)end / ((double)CLOCKS_PER_SEC) << " secs!";

    cout << endl;
    cout.fill('-');
    cout << left << setw(50) << "" << endl;

    do {
        cout << "\n>> Please enter a sentence: ";
        getline(cin, userInput);
        cout << endl;

        char* splitInput = strtok(const_cast<char*>(userInput.c_str()), DELIMITERS);
        while (splitInput != NULL)
        {
            currWord = splitInput;
            currWord = ToLowerCase(currWord);
            result += SpellCheck(hashTable, currWord);
            splitInput = strtok(NULL, DELIMITERS);
        }

        if (result > 0)
        {
            cout << "Number of words spelled incorrectly: " << result << endl;
            result = 0;
        }

        cout << "\nDo you want to enter another sentence? (y/n): ";
        cin >> response;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (toupper(response) == 'Y');

    cout << "\nBYE!!\n";

    return 0;
}

void PrintTableStats(HashTable<string>& hashTable)
{
    int largestBucket = -9999999;
    int largestIndex = 0;
    int smallestBucket = 9999999;
    int smallestIndex = 0;
    double numBuckestUsed = 0;
    ofstream outfile("OUTPUT_HashTable_Stats_programmingnotes_freeweq_com.txt");

    for (int x = 0; x < hashTable.TableSize(); ++x)
    {
        iterDec it = hashTable.begin(x);
        if (!hashTable.IsEmpty(x))
        {
            if (smallestBucket > hashTable.BucketSize(x))
            {
                smallestBucket = hashTable.BucketSize(x);
                smallestIndex = x;
            }
            if (largestBucket < hashTable.BucketSize(x))
            {
                largestBucket = hashTable.BucketSize(x);
                largestIndex = x;
            }
            ++numBuckestUsed;
            outfile << "\nBucket #" << x << ":\n";
            for (int y = 0; y < hashTable.BucketSize(x); ++y)
            {
                outfile << "\t" << it[y] << endl;
            }
        }
    }

    cout << "Complete!\n";

    cout << endl;
    cout.fill('-');
    cout << left << setw(50) << "" << endl;

    cout << "Total dictionary words = " << hashTable.TotalElems() << endl
        << "Hash table size = " << hashTable.TableSize() << endl
        << "Largest bucket size = " << largestBucket << " items at index #" << largestIndex << endl
        << "Smallest bucket size = " << smallestBucket << " items at index #" << smallestIndex << endl
        << "Total buckets used = " << numBuckestUsed << endl
        << "Total percent of hash table used = " << (numBuckestUsed / hashTable.TableSize()) * 100 << "%" << endl
        << "Average bucket size = " << (hashTable.TotalElems() / numBuckestUsed) << " items";
}

int SpellCheck(HashTable<string>& hashTable, string word)
{
    int result = 0;
    int suggestion = 0;
    string remove[256];
    int numRemove = 0;

    if (!hashTable.Count(word))
    {
        ++result;
        cout << "** " << word << ": ";

        for (unsigned x = 0; x < word.length(); ++x)
        {
            string alteration = word;
            for (char c = 'a'; c <= 'z'; ++c)
            {

                alteration[x] = c;
                if (hashTable.Count(alteration))
                {
                    cout << alteration << ", ";
                    remove[numRemove++] = alteration;
                    ++suggestion;
                    hashTable.Remove(alteration);
                }

                string insertion = word.substr(0, x) + c + word.substr(x);
                if (hashTable.Count(insertion))
                {
                    cout << insertion << ", ";
                    remove[numRemove++] = insertion;
                    ++suggestion;
                    hashTable.Remove(insertion);
                }
            }
        }

        for (unsigned x = 0; x < word.length() - 1; ++x)
        {

            string transposition = word.substr(0, x) + word[x + 1] + word[x] + word.substr(x + 2);
            if (hashTable.Count(transposition))
            {
                cout << transposition << ", ";
                remove[numRemove++] = transposition;
                ++suggestion;
                hashTable.Remove(transposition);

            }

            string deletion = word.substr(0, x) + word.substr(x + 1);
            if (hashTable.Count(deletion))
            {
                cout << deletion << ", ";
                remove[numRemove++] = deletion;
                ++suggestion;
                hashTable.Remove(deletion);
            }
        }

        while (numRemove >= 0)
        {
            hashTable.Insert(remove[numRemove--]);
        }
        if (suggestion < 1)
        {
            cout << "No spelling suggestion found...";
        }
        cout << endl << endl;
    }

    return result;
}

string ToLowerCase(string word)
{
    for (unsigned x = 0; x < word.length(); ++x)
    {
        word[x] = tolower(word[x]);
    }
    return word;
}