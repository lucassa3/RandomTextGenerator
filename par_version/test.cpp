#include <boost/mpi.hpp>
#include <boost/mpi.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
namespace mpi = boost::mpi;
using namespace std;
int main(int argc, char *argv[]) {
    // Initialize the MPI environment.
    mpi::environment env(argc, argv);
    mpi::communicator world;

    vector<string> words = { "foo", "bar", "baz", "..." };
    const int wordCount = words.size();
    const int wordsPerProcess = wordCount / world.size();
    vector<vector<string> > wordsByProcess(world.size(), vector<string>());
    for (int j = 0; j < world.size(); ++j) {
        for (int k = 0, wordIndex = j * wordsPerProcess + k;
             k < wordsPerProcess && wordIndex < wordCount; ++k, ++wordIndex) {
            wordsByProcess[j].push_back(words[wordIndex]);
        }
    }

    vector<string> subWords;
    mpi::scatter(world, wordsByProcess, subWords, 0);
    // subWords is equal to wordsByProcess[world.rank()] here in every process.
}