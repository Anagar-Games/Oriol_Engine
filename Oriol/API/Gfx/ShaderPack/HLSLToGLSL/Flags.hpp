// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_FLAGS_HPP
#define OL_FLAGS_HPP

namespace OL
{
    class Flags
    {
    public:
        Flags() = default;
        Flags(const Flags&) = default;
        Flags& operator=(const Flags&) = default;

        inline Flags(unsigned int flags_a) : bit_mask_ {flags_a}
        {}

        inline bool SetOnce(unsigned int flag_a)
        {
            if (!All(flag_a))
            {
                *this << flag_a;
                return true;
            }
            return false;
        }

        inline void Insert(unsigned int flag_a)
        {
            bit_mask_ |= flag_a;
        }

        inline void Remove(unsigned int flag_a)
        {
            bit_mask_ &= (~flag_a);
        }

        inline Flags& operator<<(unsigned int flag_a)
        {
            Insert(flag_a);
            return *this;
        }

        inline bool Any(unsigned int flags_a) const
        {
            return ((bit_mask_ & flags_a) != 0);
        }

        inline bool All(unsigned int flags_a) const
        {
            return ((bit_mask_ & flags_a) == flags_a);
        }

        inline bool operator()(unsigned int flag_a) const
        {
            return Any(flag_a);
        }

        inline operator unsigned int() const
        {
            return bit_mask_;
        }

    private:
        unsigned int bit_mask_ = 0;
    };
} // namespace OL
#endif
