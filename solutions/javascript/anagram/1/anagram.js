//
// This is only a SKELETON file for the 'Anagram' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const findAnagrams = (text,arr ) => {

  const result = [];

  for(const a of arr){
    
    if(text.toLowerCase() === a.toLowerCase()) continue;

    if(a.toLowerCase().split("").sort().join("") === text.toLowerCase().split("").sort().join("")){
      result.push(a);
    }
  }

   return result;
};
