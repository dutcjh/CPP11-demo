#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <cstdarg>
#include <map>

using namespace std;

typedef short PIXEL_VALUE;
typedef long long PIXEL_COUNT;
typedef long long PIXEL_INDEX;


inline PIXEL_VALUE abs_diff(PIXEL_VALUE lhs, PIXEL_VALUE rhs)
{
	if (lhs == -1 || rhs == -1)
		return -1;
	return (lhs > rhs ? lhs - rhs : rhs - lhs);
}


// RLEѹ�������������
typedef pair<PIXEL_VALUE, PIXEL_COUNT> RLE_PAIR;
class PIXEL_RLE_CONTAINER : public list < RLE_PAIR > {
public:
	typedef list < RLE_PAIR >::iterator PAIR_ITERATOR;
	struct PIXEL_RLE {	// RLEѹ�������������е�����
		PAIR_ITERATOR pair;
		PIXEL_COUNT offset;		// ��RLE_PAIR���ƫ��
		PIXEL_INDEX index;		// ������RLE_CONTAINER���������
		PIXEL_RLE_CONTAINER *base;

		bool isNonePixel() const { return index == -1; }
		PIXEL_VALUE getValue() const { return pair->first; }

		PIXEL_RLE operator+ (const PIXEL_COUNT &i) const
		{
			PIXEL_COUNT add_offset = i;
			PIXEL_RLE res = *this;

			while (add_offset != 0)
			{
				if (add_offset > 0)
				{
					if (res.pair->second > res.offset + add_offset)
					{
						res.index += add_offset;
						res.offset += add_offset;
						add_offset -= add_offset;
					}
					else
					{
						add_offset -= res.pair->second - res.offset;
						res.index += res.pair->second - res.offset;
						res.pair++;
						res.offset = 0;

						if (res.pair == res.base->end())
						{
							return res.base->none_pixel();
						}
					}
				}
				else
				{
					if (res.offset + add_offset >= 0)
					{
						res.index += add_offset;
						res.offset += add_offset;
						add_offset -= add_offset;
					}
					else
					{
						if (res.pair == res.base->begin())
						{
							return res.base->none_pixel();
						}

						add_offset -= -1 - res.offset;
						res.index += -1 - res.offset;
						res.pair--;
						res.offset = res.pair->second - 1;
					}
				}
			}

			return res;
		}

		// �����һ��Ҫ��������أ�ֻ�账��RLE_PAIR����β�������ؼ���
		PIXEL_RLE getNextProcPixel() const
		{
			if (offset == pair->second - 1)	// �����RLE_PAIR��β�����أ��ͷ�����һ��RLE_PAIR���ײ�����
			{
				return *this + 1;
			}
			else
			{	// ���򷵻�RLE_PAIR��β������
				PIXEL_COUNT dis = pair->second - 1 - offset;
				return *this + dis;
			}
		}
	};

public:
	PIXEL_RLE begin_pixel()
	{
		PIXEL_RLE res;
		res.pair = begin();
		res.offset = 0;
		res.index = 0;
		res.base = this;
		return res;
	}

	PIXEL_RLE none_pixel()
	{
		PIXEL_RLE res;
		res.pair = end();
		res.offset = 0;
		res.index = -1;
		res.base = this;
		return res;
	}
};

// �����ʾ����������
class PIXEL_CONTAINER : public map < PIXEL_INDEX, PIXEL_VALUE > {
private:
	PIXEL_COUNT width;
	PIXEL_RLE_CONTAINER cache;
	PIXEL_COUNT has_push;

public:
	PIXEL_CONTAINER(PIXEL_COUNT _width) : map < PIXEL_INDEX, PIXEL_VALUE >(), width(_width), has_push(0) { cout << _width << endl; }

	void output(PIXEL_COUNT all_count)
	{
		for (iterator it = begin(); it != end(); ++it)
		{
			iterator next = it;
			next++;

			if (next == end())
			{
				push_to_cache(it->second, all_count - it->first);
			}
			else
			{
				PIXEL_COUNT count = next->first - it->first;
				PIXEL_COUNT nextCount = 0;
				if (has_push / width < (has_push + count) / width)
				{
					nextCount = (has_push + count) % width;
				}
				push_to_cache(it->second, count - nextCount);
				push_to_cache(next->second, nextCount);
			}
		}
		out_from_cache();
	}

private:
	void push_to_cache(PIXEL_VALUE _value, PIXEL_COUNT _count)
	{
		PIXEL_RLE_CONTAINER::reverse_iterator pri = cache.rbegin();
		if (pri == cache.rend() || pri->first != _value)
		{
			cache.push_back(make_pair(_value, _count));
		}
		else
		{
			pri->second += _count;
		}
		has_push += _count;
	}

	void out_from_cache()
	{
		for (PIXEL_RLE_CONTAINER::iterator pi = cache.begin(); pi != cache.end(); ++pi)
		{
			cout << pi->first << ' ' << pi->second << endl;
		}
		cout << "0 0" << endl;
	}
};

class processor {
private:
	enum ADJACENT_TYPE {
		UPPER_LEFT = 0,
		UPPER,
		UPPER_RIGHT,
		LEFT,
		RIGHT,
		LOWER_LEFT,
		LOWER,
		LOWER_RIGHT,
		NOT_ADJACENT
	};

private:
	PIXEL_COUNT count;					// δ��������ظ���
	PIXEL_COUNT width;
	bool inputFinish;

private:
	PIXEL_RLE_CONTAINER inputCache;			// RLEѹ������������뻺��
	PIXEL_RLE_CONTAINER::PIXEL_RLE nextPixel;	// ����������
	PIXEL_CONTAINER outputCache;

public:
	processor(PIXEL_COUNT _width) :count(0), width(_width), inputFinish(false), outputCache(_width) {}

	void push_back(PIXEL_VALUE _value, PIXEL_COUNT _count)
	{
		if (_value == 0 && _count == 0)
		{
			inputFinish = true;
		}
		else
		{
			inputCache.push_back(make_pair(_value, _count));
			if (count == 0)	// ��һ������
			{
				nextPixel = inputCache.begin_pixel();
			}

			count += _count;
		}

		// Ҫ����һ��RLE�ڵ��ϵ����أ�����Ҫ�ȴ��㹻��ĺ������루��Ҫ������������һ�е����ݣ�
		// ����ÿ�η���ڵ�ʱ�������Դ������ܶ�����ص�
		process();
	}

private:
	void process()
	{
		if (inputCache.begin() != inputCache.end())
		{
			while (canProcOnePixel(nextPixel))
			{
				processOnePixel(nextPixel);
				nextPixel = nextPixel.getNextProcPixel();
			}
		}

		if (inputFinish)
		{
			outputCache.output(count);
		}
	}

	bool canProcOnePixel(const PIXEL_RLE_CONTAINER::PIXEL_RLE &_pixel)
	{
		if (_pixel.isNonePixel()) return false;
		if (inputFinish) return true;

		// ����һ��RLE�ڵ㣬����ֻ��Ҫ������β�������أ������������ظ�����Χ8�����ؽ��д����ɡ�
		// ������������Ҫβ�����ص����·������·������ݡ�
		return (count > _pixel.index + (width + 1) + (width + 1));
	}

	// ����һ�����أ�����������Χ8�����ؽ��б�Ե��⣬����������
	void processOnePixel(const PIXEL_RLE_CONTAINER::PIXEL_RLE &_pixel)
	{
		if (outputCache.find(_pixel.index) == outputCache.end())
		{
			outputCache.insert(make_pair(_pixel.index, calcEdgeValue(_pixel)));
		}

		for (int i = UPPER_LEFT; i < NOT_ADJACENT; i++)
		{
			PIXEL_COUNT offset;
			if (getOffSet((ADJACENT_TYPE)i, _pixel.index, offset))
			{
				PIXEL_RLE_CONTAINER::PIXEL_RLE adjacentPixel = _pixel + offset;
				if (!adjacentPixel.isNonePixel()
					&& outputCache.find(adjacentPixel.index) == outputCache.end())
				{
					outputCache.insert(make_pair(adjacentPixel.index, calcEdgeValue(adjacentPixel)));
				}
			}
		}
	}

	// �����������������������صĻҶ�ֵ���Բ�ֵ�����ֵ����Ե���ʱ��һ�����صĴ���
	PIXEL_VALUE calcEdgeValue(const PIXEL_RLE_CONTAINER::PIXEL_RLE &_pixel)
	{
		PIXEL_VALUE result = 0;
		PIXEL_VALUE curValue = _pixel.getValue();
		for (int i = UPPER_LEFT; i < NOT_ADJACENT; i++)
		{
			PIXEL_COUNT offset;
			if (getOffSet((ADJACENT_TYPE)i, _pixel.index, offset))
			{
				PIXEL_RLE_CONTAINER::PIXEL_RLE adjacentPixel = _pixel + offset;
				if (!adjacentPixel.isNonePixel())
				{
					PIXEL_VALUE adjValue = adjacentPixel.getValue();
					PIXEL_VALUE absDiffValue = abs_diff(curValue, adjValue);
					result = (result > absDiffValue ? result : absDiffValue);
				}
			}
		}
		return result;
	}

	// �����������ص����ͼ���ƫ��
	bool getOffSet(ADJACENT_TYPE _type, PIXEL_INDEX _index, PIXEL_COUNT &offset)
	{
		PIXEL_COUNT col = _index%width, row = _index / width;

		switch (_type)
		{
		case UPPER_LEFT:
			row--; col--;
			break;
		case UPPER:
			row--;
			break;
		case UPPER_RIGHT:
			row--; col++;
			break;
		case LEFT:
			col--;
			break;
		case RIGHT:
			col++;
			break;
		case LOWER_LEFT:
			row++; col--;
			break;
		case LOWER:
			row++;
			break;
		case LOWER_RIGHT:
			row++; col++;
			break;
		default:
			return false;
		}

		if (col < 0 || col >= width || row < 0)
			return false;

		offset = row * width + col - _index;
		return true;
	}
};


int main()
{
	int width;
	PIXEL_VALUE pixel;
	PIXEL_COUNT count;

	do
	{
		cin >> width;
		processor proc(width);

		if (width > 0)
		{
			do
			{
				cin >> pixel >> count;
				proc.push_back(pixel, count);
			} while (pixel != 0 || count != 0);
		}
	} while (width != 0);

	return 0;
}
