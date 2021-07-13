class VotingMachine:
    def __init__(self):
        self.candidates = dict()

    def cast_vote(self, candidate):
        if candidate in self.candidates.keys():
            self.candidates[candidate] += 1
        else:
            self.candidates[candidate] = 1

    def candidates_name(self):
        print("Voted Candidates: ", end="")
        print(", ".join(self.candidates.keys()))

    def display_result(self):
        maximum_candidates = list()
        maximum_vote = 0

        for i in self.candidates:
            if self.candidates[i] > maximum_vote:
                maximum_vote = self.candidates[i]
                maximum_candidates = list()
            if self.candidates[i] == maximum_vote:
                maximum_candidates.append(i)

        maximum_candidates.sort()
        print(f"Candidates with maximum votes {maximum_vote}: ", end="")
        print(maximum_candidates)


if __name__ == "__main__":
    v1 = VotingMachine()
    while True:
        v1.candidates_name()
        name = input("Enter name to cast vote: ")
        if name == "EXIT!":
            break
        v1.cast_vote(name)

    v1.display_result()
