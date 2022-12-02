#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the new Elo ratings of the two images
void calculateEloRatings(int &elo1, int &elo2, bool userChoice)
{
    // Calculate the expected scores for each image
    double exp1 = 1.0 / (1.0 + pow(10.0, (double)(elo2 - elo1) / 400.0));
    double exp2 = 1.0 / (1.0 + pow(10.0, (double)(elo1 - elo2) / 400.0));

    // Calculate the new Elo ratings based on the user's choice
    if (userChoice)
    {
        // If the user chose image 1, increase its rating and decrease image 2's rating
        elo1 += 32.0 * (1.0 - exp1);
        elo2 += 32.0 * (0.0 - exp2);
    }
    else
    {
        // If the user chose image 2, increase its rating and decrease image 1's rating
        elo1 += 32.0 * (0.0 - exp1);
        elo2 += 32.0 * (1.0 - exp2);
    }
}

int main()
{
    // Initialize the Elo ratings of the two images
    int elo1 = 1500;
    int elo2 = 1500;

    // Continue asking the user to rate the images until they enter 'q' to quit
    while (true)
    {
        // Prompt the user to rate the images
        cout << "Enter 1 to rate image 1, 2 to rate image 2, or q to quit: ";
        char choice;
        cin >> choice;

        // Check if the user entered 'q' to quit
        if (choice == 'q')
        {
            break;
        }

        // Check if the user entered 1 or 2 to rate the images
        if (choice == '1')
        {
            // Calculate the new Elo ratings with the user choosing image 1
            calculateEloRatings(elo1, elo2, true);
        }
        else if (choice == '2')
        {
            // Calculate the new Elo ratings with the user choosing image 2
            calculateEloRatings(elo1, elo2, false);
        }
        else
        {
            // If the user entered an invalid choice, print an error message and continue
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Print the new Elo ratings of the images
        cout << "Image 1 rating: " << elo1 << endl;
        cout << "Image 2 rating: " << elo2 << endl;
    }

    return 0;
}
