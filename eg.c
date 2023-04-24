/*
Design a function called 'generate_summary' that takes in two arguments: 
a text file path (string) containing a document to summarize and a summarization ratio (float) between 0 and 1 representing the proportion of the original document length. 
Implement the TextRank algorithm to generate a summary of the input document. 
The function should return the summary as a string, with sentences separated by a single space. 
Account for edge cases, such as an empty document or an invalid summarization ratio, by returning appropriate error messages. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_SENTENCES 1000

// Function to remove punctuation from a string
void remove_punctuation(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        *dst = *src++;
        dst += (*dst != '.' && *dst != ',' && *dst != '?' && *dst != '!' && *dst != ';' && *dst != ':' && *dst != '"' && *dst != '(' && *dst != ')' && *dst != '[' && *dst != ']' && *dst != '{' && *dst != '}');
    }
    *dst = '\0';
}

// Function to calculate the cosine similarity between two vectors
double cosine_similarity(double *vec1, double *vec2, int vec_len) {
    double dot_product = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;
    for (int i = 0; i < vec_len; i++) {
        dot_product += vec1[i] * vec2[i];
        norm1 += vec1[i] * vec1[i];
        norm2 += vec2[i] * vec2[i];
    }
    if (norm1 == 0.0 || norm2 == 0.0) {
        return 0.0;
    }
    return dot_product / (sqrt(norm1) * sqrt(norm2));
}

// Function to generate a summary of a document
char *generate_summary(char *file_path, float ratio) {
    // Check if file path is valid
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        return "Error: File path is invalid.";
    }
    // Check if ratio is valid
    if (ratio <= 0 || ratio >= 1) {
        return "Error: Invalid ratio.";
    }
    // Read in document
    char *document = malloc(MAX_SENTENCE_LENGTH * MAX_NUM_SENTENCES);
    char *line = malloc(MAX_LINE_LENGTH);
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strcat(document, line);
    }
    // Check if document is empty
    if (strlen(document) == 0) {
        return "Error: Empty document.";
    }
    // Split document into sentences
    char *sentences[MAX_NUM_SENTENCES];
    int num_sentences = 0;
    char *token = strtok(document, ".?!");
    while (token != NULL) {
        // Remove punctuation
        remove_punctuation(token);
        // Remove leading and trailing whitespace
        while (isspace(token[0])) {
            token++;
        }
        int len = strlen(token);
        while (isspace(token[len - 1])) {
            token[len - 1] = '\0';
            len--;
        }
        // Add sentence to array
        sentences[num_sentences] = token;
        num_sentences++;
        token = strtok(NULL, ".?!");
    }
    // Split sentences into words
    char *words[MAX_NUM_SENTENCES][MAX_LINE_LENGTH];
    int num_words[MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        int j = 0;
        token = strtok(sentences[i], " ");
        while (token != NULL) {
            // Remove leading and trailing whitespace
            while (isspace(token[0])) {
                token++;
            }
            int len = strlen(token);
            while (isspace(token[len - 1])) {
                token[len - 1] = '\0';
                len--;
            }
            // Add word to array
            words[i][j] = token;
            j++;
            token = strtok(NULL, " ");
        }
        num_words[i] = j;
    }
    // Calculate word frequencies
    int num_unique_words = 0;
    char *unique_words[MAX_LINE_LENGTH];
    int word_frequencies[MAX_LINE_LENGTH];
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_words[i]; j++) {
            int k = 0;
            while (k < num_unique_words) {
                if (strcmp(words[i][j], unique_words[k]) == 0) {
                    word_frequencies[k]++;
                    break;
                }
                k++;
            }
            if (k == num_unique_words) {
                unique_words[num_unique_words] = words[i][j];
                word_frequencies[num_unique_words] = 1;
                num_unique_words++;
            }
        }
    }
    // Calculate word importance score
    double word_importance_scores[MAX_LINE_LENGTH];
    for (int i = 0; i < num_unique_words; i++) {
        word_importance_scores[i] = (double) word_frequencies[i] / num_unique_words;
    }
    // Calculate sentence importance score
    double sentence_importance_scores[MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        double sentence_importance_score = 0.0;
        for (int j = 0; j < num_words[i]; j++) {
            int k = 0;
            while (k < num_unique_words) {
                if (strcmp(words[i][j], unique_words[k]) == 0) {
                    sentence_importance_score += word_importance_scores[k];
                    break;
                }
                k++;
            }
        }
        sentence_importance_scores[i] = sentence_importance_score;
    }
    // Calculate sentence similarity matrix
    double sentence_similarity_matrix[MAX_NUM_SENTENCES][MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_sentences; j++) {
            if (i == j) {
                sentence_similarity_matrix[i][j] = 0.0;
            } else {
                sentence_similarity_matrix[i][j] = cosine_similarity(words[i], words[j], num_words[i]);
            }
        }
    }
    // Calculate sentence rank vector
    double sentence_rank_vector[MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        sentence_rank_vector[i] = 1.0 / num_sentences;
    }
    // Calculate sentence rank vector using power iteration
    double new_sentence_rank_vector[MAX_NUM_SENTENCES];
    while (1) {
        for (int i = 0; i < num_sentences; i++) {
            double sentence_rank_sum = 0.0;
            for (int j = 0; j < num_sentences; j++) {
                sentence_rank_sum += sentence_similarity_matrix[i][j] * sentence_rank_vector[j];
            }
            new_sentence_rank_vector[i] = sentence_rank_sum;
        }
        double diff = 0.0;
        for (int i = 0; i < num_sentences; i++) {
            diff += fabs(new_sentence_rank_vector[i] - sentence_rank_vector[i]);
        }
        if (diff < 0.0001) {
            break;
        }
        for (int i = 0; i < num_sentences; i++) {
            sentence_rank_vector[i] = new_sentence_rank_vector[i];
        }
    }
    // Calculate sentence importance score
    double sentence_importance_scores2[MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        sentence_importance_scores2[i] = sentence_importance_scores[i] * sentence_rank_vector[i];
    }
    // Sort sentences by importance score
    char *sorted_sentences[MAX_NUM_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        int j = 0;
        while (j < i) {
            if (sentence_importance_scores2[i] > sentence_importance_scores2[j]) {
                break;
            }
            j++;
        }
        for (int k = i; k > j; k--) {
            sorted_sentences[k] = sorted_sentences[k - 1];
        }
        sorted_sentences[j] = sentences[i];
    }
    // Print summary
    for (int i = 0; i < num_sentences; i++) {
        printf("%s. ", sorted_sentences[i]);
    }
    printf("\n");
    return 0;
}
