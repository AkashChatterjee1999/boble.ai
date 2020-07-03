
                    # Code written by :Akash Chatterjee
                    # Date ; 07/03/2020
                    # Code for a better tommorow

import sys
#This function tries to find the dissimlarity score or
#the score required to transfrom 1 string to another
def _match_handler(st1,st2):
    m,n = len(st1),len(st2)
    dp,ans = [[0 for i in range(n+1)]for j in range(m+1)],-1
    for i in range(m+1): dp[i][0] = i
    for i in range(n+1): dp[0][i] = i 
    for i in range(1,m+1):
        for j in range(1,n+1):
            if st1[i-1]==st2[j-1]:dp[i][j] = dp[i-1][j-1]
            else:dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
    return dp[-1][-1]

#This function converts each instance of a word into an object
#this is extremly necessary for sorting
class word_bundle:
    def __init__(self,word,dissimilarity,frequency):
        self.word = word 
        self.dissimilarity = dissimilarity
        self.frequency = frequency
    def __lt__(self,other):
        return self.dissimilarity<other.dissimilarity if self.dissimilarity!=other.dissimilarity else self.frequency>other.frequency

    #this string stores the path of the file
path_to_file = sys.argv[1]
    #this stores the misspelled given as input in the cli interface
typed_word = sys.argv[2].lower()
    #this list stores the strings and is used for sorting based on matching 
internal_associative_dict = []
    #this var stores the current file ptr
current_file_ptr = open(path_to_file,"r")
    #this reads the lines from the file as input
file_lines = current_file_ptr.readlines()
for content in file_lines:
    this_word,frequency = content.split(', ')
    calculated_dissimilarity_score = _match_handler(typed_word,this_word.lower())
    internal_associative_dict.append(word_bundle(this_word,calculated_dissimilarity_score,frequency))
internal_associative_dict.sort()

        #based on the score and the matching frequency 
        # given in input file we get the output
        # for same score we print the sorted list of frequnecy words
high_score = internal_associative_dict[0].dissimilarity
for i in internal_associative_dict:
    if high_score==i.dissimilarity:print(i.word,end=" ")

    #finally we try to print the mispelled words