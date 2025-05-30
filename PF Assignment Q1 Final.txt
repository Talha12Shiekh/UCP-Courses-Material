#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
bool isValidStudentID(char* id);     
bool isValidName(char* name);        
bool isValidCGPA(char* cgpa);        
bool isValidProgram(char* program);  
void validateStudentRecords(char* inputFile, char* outputFile); 

int main() {
    char input[] = "students.txt"; // input file
    char output[] = "validated_students.txt"; // output file

    validateStudentRecords(input, output); // Start validation process
    cout << "Validation completed. Check validated_students.txt\n";

    return 0;
}

// A function to check the student ID is in the correct format (STD followed by 3 digits)
// Parameter ( char* id ) : Student ID
bool isValidStudentID(char* id) {
    bool startsWithSTD = (id[0] == 'S' && id[1] == 'T' && id[2] == 'D');
    bool hasThreeDigits = (id[3] >= '0' && id[3] <= '9') &&
        (id[4] >= '0' && id[4] <= '9') &&
        (id[5] >= '0' && id[5] <= '9');
    bool endsProperly = (id[6] == '\0');

    return startsWithSTD && hasThreeDigits && endsProperly;
}

// A function to check that the name contains only alphabets and is not empty
// Parameter ( char* name ) : Student name
bool isValidName(char* name) {
    if (name[0] == '\0') return false;

    char* ptr = name;
    while (*ptr != '\0') {
        bool isUpper = (*ptr >= 'A' && *ptr <= 'Z');
        bool isLower = (*ptr >= 'a' && *ptr <= 'z');
        bool isAlphabetic = isUpper || isLower;

        if (!isAlphabetic) return false;
   
        ptr++;
    }

    return true;
}

// A function that validates that CGPA that is a ( floating-point number between 0.0 and 4.0 )
// Parameter ( char* cgpa ) : Student CGPA
bool isValidCGPA(char* cgpa) {
    if (cgpa[0] == '\0' || cgpa[0] == '-') return false;

    float value = 0;
    bool pointSeen = false;
    float divisor = 10;

    for (int i = 0; cgpa[i] != '\0'; i++) {
        char ch = cgpa[i];

        if (ch == '.') {
            if (pointSeen) return false; // only one dot allowed
            pointSeen = true;
        }
        else if (ch >= '0' && ch <= '9') {
            if (!pointSeen) {
                if (i > 0) return false; // only one digit allowed before decimal
                value = ch - '0';
            }
            else {
                value += (ch - '0') / divisor;
                divisor *= 10;
            }
        }
        else {
            return false;
        }
    }

    return (value >= 0.0 && value <= 4.0);
}

// A function to check that if the Program field is non-empty
// Parameter ( char* program ) : Student Program
bool isValidProgram(char* program) {
    char* ptr = program;
    while (*ptr != '\0') {
        if (*ptr != ' ') {
            return true;
        }
        ptr++;
    }
    return false;
}


// A function to read student data from file, validates fields, and writes results
// Parameter ( char* inputFile ) : Path to input file
// Parameter ( char* outputFile ) : Path to output file
void validateStudentRecords(char* inputFile, char* outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);

    char line[100];

    while (in.getline(line, 100)) {
        char* id = line;
        char* name = 0;
        char* cgpa = 0;
        char* program = 0;

        
        int fieldCount = 0;
        char* ptr = line;

        while (*ptr != '\0') {
            if (*ptr == ',') { // Manually split the line into fields using comma
                *ptr = '\0';
                fieldCount++;
                if (fieldCount == 1) name = ptr + 1;
                else if (fieldCount == 2) cgpa = ptr + 1;
                else if (fieldCount == 3) program = ptr + 1;
            }
            ptr++;
        }

        // If fields are missing
        if (fieldCount != 3 || name == 0 || cgpa == 0 || program == 0) {
            out << id << "," << name << "," << cgpa << "," << program << " -> invalid\n";
            continue;
        }

        // Validate each field using functions
        bool valid = isValidStudentID(id) &&
            isValidName(name) &&
            isValidCGPA(cgpa) &&
            isValidProgram(program);

        // Output result
        out << id << "," << name << "," << cgpa << "," << program;

        // If all fields are valid, print "valid", otherwise print "invalid".
        if (valid) out << " -> valid" << endl;
        else out << " -> invalid" << endl;
    }

    in.close();
    out.close();
}
