require "levenshtein_ruby/version"
require "levenshtein_ruby/levenshtein_ruby"

module Levenshtein
  def self.normalized_distance(a1, a2)
    size  = [a1.size, a2.size].max
    if a1.size == 0 and a2.size == 0
      0.0
    elsif a1.size == 0
      a2.size.to_f/size
    elsif a2.size == 0
      a1.size.to_f/size
    else
      self.distance(a1, a2).to_f/size
    end
  end
end
