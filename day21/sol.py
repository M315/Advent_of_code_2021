# DP
# Save the wins of each player in a tuple for every stage in the game
# As each player can be in 10 possitions and they can have at most 20 points (if the y have more they already won)
# The total options are 10 * 10 * 21 * 21 ~ 40k

DP = {} # Dictionary with the game results

def wins(p1, p2, s1, s2):
	# Player 1 won
	if s1 >= 21:
		return (1, 0)
	
	# Player 2 won
	if s2 >= 21:
		return (0, 1)
	
	# If we have already seen the stage use it
	if (p1, p2, s1, s2) in DP:
		return DP[(p1, p2, s1, s2)]
		
	# init wins to 0
	w = (0,0)
	
	# Roll the 3 dices
	for die1 in [1,2,3]:
		for die2 in [1,2,3]:
			for die3 in [1,2,3]:
				# Compute the new possition and score for each option
				new_p1 = (p1 + die1 + die2 + die3) % 10
				new_s1 = s1 + new_p1 + 1
				
				# Make the other player play and get the results
				# The results are in inverse orther as we have change the orther of play
				w2, w1 = wins(p2, new_p1, s2, new_s1)
				
				# Add the results to the other throws
				w = (w[0] + w1, w[1] + w2)
	
	# Save the result
	DP[(p1, p2, s1, s2)] = w
	return w

def main():
	p1 = 4 - 1
	p2 = 10 - 1
	
	print(max(wins(p1, p2, 0, 0)))

if __name__ == "__main__":
	main()
