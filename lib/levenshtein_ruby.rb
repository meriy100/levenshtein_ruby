require "levenshtein_ruby/version"
require "levenshtein_ruby/levenshtein_ruby"

class Levenshtein
  def normalized_distance(a1, a2, threshold=nil, options={})
    size  = [a1.size, a2.size].max

    if a1.size == 0 and a2.size == 0
      0.0
    elsif a1.size == 0
      a2.size.to_f/size
    elsif a2.size == 0
      a1.size.to_f/size
    else
      if threshold
        if d = self.distance(a1, a2, (threshold*size).to_i+1)
          d.to_f/size
        else
          nil
        end
      else
        self.distance(a1, a2).to_f/size
      end
    end
  end
end
