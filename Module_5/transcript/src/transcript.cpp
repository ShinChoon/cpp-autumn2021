#include "transcript.hpp"

void TranscriptRegistry::Add(const Transcript &TR)
{   
    this->TRlist.push_back(TR);
}

void TranscriptRegistry::RemoveById(const std::string &SI)
{

    TRlist.erase(remove_if(TRlist.begin(), TRlist.end(), [SI](Transcript &TR)
                           { return SI == TR.student_id; }));
}

std::vector<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string &SI)const
{
    std::vector<Transcript>::const_iterator TI;

    TI = find_if(TRlist.begin(), TRlist.end(), [SI](const Transcript &TR)
                 { return SI == TR.student_id; });
    return TI;
}

std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(const std::string &name) const
{
    // std::list<std::pair<std::string, size_t>> registerlist;
    // for (auto i : TRlist)
    // {
    //     auto TI = find_if(i.grades.begin(), i.grades.end(), [name](const std::pair<std::string, size_t> &TR)
    //                   { return TR.first == name; });
    //     registerlist.push_back(std::make_pair(i.student_id, TI->second));
    // }
    // return registerlist;
    std::list<std::pair<std::string, size_t>> registerlist;
    for (auto i : TRlist)
    {
        for (auto itr = i.grades.begin(); itr != i.grades.end(); itr++)
        {
            if (itr->first == name)
            {
                registerlist.push_back(std::make_pair(i.student_id, itr->second));
            }
        }
    }
    return registerlist;
}

const std::vector<Transcript> TranscriptRegistry::GetTranscripts()const
{
    return TRlist;
}