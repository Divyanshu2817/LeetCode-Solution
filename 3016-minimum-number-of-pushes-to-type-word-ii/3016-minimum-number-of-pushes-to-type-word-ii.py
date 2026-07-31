class Solution:
    def minimumPushes(self, word: str) -> int:
        # Count frequency of each character
        counts = Counter(word)
        
        # Sort frequencies in descending order
        freqs = sorted(counts.values(), reverse=True)
        
        total_pushes = 0
        for i, freq in enumerate(freqs):
            multiplier = (i // 8) + 1
            total_pushes += freq * multiplier
            
        return total_pushes